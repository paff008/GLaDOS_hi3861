#include "range_finding.h"

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "ohos_init.h"
#include "cmsis_os2.h"
#include "iot_gpio.h"
#include "iot_gpio_ex.h"

#include "iot_i2c.h"

/* #define AHT20_BAUDRATE (400 * 1000)
#define AHT20_I2C_IDX 0 */

MSG_RANGE meg_range;
osMessageQueueId_t mid_MagRange;

void sr04_init(void)
{	
    IoTGpioInit(TRIG_PIN);
	IoSetFunc(TRIG_PIN,IOT_IO_FUNC_GPIO_11_GPIO);
    IoTGpioSetDir(TRIG_PIN,IOT_GPIO_DIR_OUT);
    IoTGpioSetOutputVal(TRIG_PIN,IOT_GPIO_VALUE0);
	
    IoTGpioInit(ECHO_PIN);
	IoSetFunc(ECHO_PIN,IOT_IO_FUNC_GPIO_12_GPIO);
    IoTGpioSetDir(ECHO_PIN,IOT_GPIO_DIR_IN);
}

/*获取距离*/
float sr04_get_distance(void)
{
    int distance;  //计算出的距离
    float distance_f;
	int reflex_time;
    IotGpioValue val_echo =IOT_GPIO_VALUE0;
	//return 9;          ///////////////////////////////////////这里要注释掉！！！测试用
	//PC8高电平
	IoTGpioSetOutputVal(TRIG_PIN,IOT_GPIO_VALUE1);
	hi_udelay(15);	//持续10us以上
	IoTGpioSetOutputVal(TRIG_PIN,IOT_GPIO_VALUE0);;//trig低电平

    do{
        IoTGpioGetInputVal(ECHO_PIN,&val_echo);
    }while(val_echo == IOT_GPIO_VALUE0);                        //等待echo高电平
	
	//等待echo出现高电平    
	reflex_time=0;
    do{
        IoTGpioGetInputVal(ECHO_PIN,&val_echo);
        reflex_time++;
		hi_udelay(1);
		
		//如果超时，就返回一个错误码
		if(reflex_time >= 10000)
		return -1;
    }while(val_echo == IOT_GPIO_VALUE0);

	//测量高电平的时间
	reflex_time=0;
    while(val_echo == IOT_GPIO_VALUE1){
        IoTGpioGetInputVal(ECHO_PIN,&val_echo);
        reflex_time++;
		hi_udelay(9);	//9us == 3mm
		
		//如果超时，就返回一个错误码
		if(reflex_time >= 1000000)
		    return -2;
    }

	//由于测量的时间，就是超声波从发射到返回的时间	
	distance_f = (float)reflex_time*0.15;
    printf("获取的距离为 %.2f cm\n",distance_f);
	return distance_f;
}
static void *Range_finding(const void *arg){
    (void)arg;
    float distance;
    osStatus_t status;
    
    while(1){
        sr04_init();
        distance = sr04_get_distance();
        meg_range.meg_distance = distance;
        osMessageQueuePut(mid_MagRange, &meg_range, 0U, 0U);
        osThreadYield();                                            // suspend thread   
        osDelay(100);
    }
}
static void RangeDemo(void)
{
    mid_MagRange = osMessageQueueNew(16, 100, NULL);
    if (mid_MagRange == NULL) {
        printf("Falied to create Message Queue!\n");
    }
    osThreadAttr_t attr;


    attr.name = "Range_finding";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = 4096;
    attr.priority = 25;

    if (osThreadNew((osThreadFunc_t)Range_finding, NULL, &attr) == NULL) {
        printf("[LedExample] Failed to create LedTask!\n");
    }
}

//APP_FEATURE_INIT(RangeDemo);
