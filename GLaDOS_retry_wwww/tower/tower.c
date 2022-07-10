
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "ohos_init.h"
#include "cmsis_os2.h"
#include "iot_gpio.h"
#include "hi_time.h"
#include "iot_gpio_ex.h"
#include "tower.h"

#define IOT_GPIO_SERVO_X 6
#define IOT_GPIO_SERVO_Y 7
//1600/18400  x轴的中心       1850/18150 y轴中心

TOWER_CONFIG tower_config = {0};

void Tower_init(){
    IoTGpioInit(IOT_GPIO_SERVO_X );
    IoSetFunc(IOT_GPIO_SERVO_X ,IOT_IO_FUNC_GPIO_6_GPIO); /* 将GPIO7定义为普通GPIO功能*/
    IoTGpioSetDir(IOT_GPIO_SERVO_X,IOT_GPIO_DIR_OUT); /* 设置GPIO7方向为输出*/
    IoTGpioSetOutputVal(IOT_GPIO_SERVO_X , IOT_GPIO_VALUE0);//初始化GPIO6为低电平
    IoTGpioInit(IOT_GPIO_SERVO_Y );
    IoSetFunc(IOT_GPIO_SERVO_Y , IOT_IO_FUNC_GPIO_7_GPIO); /* 将GPIO7定义为普通GPIO功能*/
    IoTGpioSetDir(IOT_GPIO_SERVO_Y , IOT_GPIO_DIR_OUT); /* 设置GPIO7方向为输出*/
    IoTGpioSetOutputVal(IOT_GPIO_SERVO_Y , IOT_GPIO_VALUE0);//初始化GPIO7为低电平
}

void tower_control(TOWER_CONFIG tower){
    int time_x = 1600,time_y = 1850;
    time_x =2100-((float)tower.Tower_x/(float)256)*1000;
    time_y = ((float)tower.Tower_y/(float)256)*1000+1350;
    if((time_x<1100)||(time_y<1350)||(time_x>2100)||(time_y>2350)){
        printf("tower_error1");
    }else{
        printf("舵机运行中\n");
        printf("%d,%d\n",time_x,time_y);
        for(int i = 0;i<10;i++){
            IoTGpioSetOutputVal(IOT_GPIO_SERVO_X , IOT_GPIO_VALUE1);
            hi_udelay(time_x);
            IoTGpioSetOutputVal(IOT_GPIO_SERVO_X , IOT_GPIO_VALUE0);
            hi_udelay(10000-time_x);
            IoTGpioSetOutputVal(IOT_GPIO_SERVO_Y , IOT_GPIO_VALUE1);
            hi_udelay(time_y);
            IoTGpioSetOutputVal(IOT_GPIO_SERVO_Y , IOT_GPIO_VALUE0);
            hi_udelay(10000-time_y);
        }
    }
}
