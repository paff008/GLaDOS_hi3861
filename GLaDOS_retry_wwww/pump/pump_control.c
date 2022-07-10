
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "ohos_init.h"
#include "cmsis_os2.h"
#include "iot_gpio.h"
#include "hi_time.h"
#include "iot_gpio_ex.h"
#include "pump_control.h"

#include "iot_errno.h"

#define IOT_GPIO_TOWER_H 2 //气泵控制

#define IOT_GPIO_CONTROL_H 8 //电磁阀控制

#define PUMP_IN 11  //arduino 反馈端口

#define ARDUINO_COM1 9  //arduino 控制端口1
#define ARDUINO_COM2 10  //arduino 控制端口2

void pump_init(void){
    IoTGpioInit(IOT_GPIO_TOWER_H );
    IoSetFunc(IOT_GPIO_TOWER_H ,IOT_IO_FUNC_GPIO_2_GPIO); 
    IoTGpioSetDir(IOT_GPIO_TOWER_H,IOT_GPIO_DIR_OUT);
    IoTGpioSetOutputVal(IOT_GPIO_TOWER_H , IOT_GPIO_VALUE0);


    IoTGpioInit(IOT_GPIO_CONTROL_H );
    IoSetFunc(IOT_GPIO_CONTROL_H ,IOT_IO_FUNC_GPIO_8_GPIO); 
    IoTGpioSetDir(IOT_GPIO_CONTROL_H,IOT_GPIO_DIR_OUT); 
    IoTGpioSetOutputVal(IOT_GPIO_CONTROL_H , IOT_GPIO_VALUE0);

    IoTGpioInit(PUMP_IN);
    IoSetFunc(PUMP_IN ,IOT_IO_FUNC_GPIO_11_GPIO);
    IoTGpioSetDir(PUMP_IN,IOT_GPIO_DIR_IN); 

    IoTGpioInit(ARDUINO_COM1);
    IoSetFunc(ARDUINO_COM1 ,IOT_IO_FUNC_GPIO_9_GPIO); 
    IoTGpioSetDir(ARDUINO_COM1,IOT_GPIO_DIR_OUT);
    IoTGpioSetOutputVal(ARDUINO_COM1 , IOT_GPIO_VALUE0);

    IoTGpioInit(ARDUINO_COM2);
    IoSetFunc(ARDUINO_COM2 ,IOT_IO_FUNC_GPIO_10_GPIO); 
    IoTGpioSetDir(ARDUINO_COM2,IOT_GPIO_DIR_OUT);
    IoTGpioSetOutputVal(ARDUINO_COM2 , IOT_GPIO_VALUE0);
}

void pump_on(){
    IoTGpioSetOutputVal(IOT_GPIO_TOWER_H , IOT_GPIO_VALUE1);

}
void pump_off(){
    IoTGpioSetOutputVal(IOT_GPIO_TOWER_H , IOT_GPIO_VALUE0);
}
void pump_contol_on(){
    IoTGpioSetOutputVal(IOT_GPIO_CONTROL_H , IOT_GPIO_VALUE1);
}
void pump_contol_off(){
    IoTGpioSetOutputVal(IOT_GPIO_CONTROL_H , IOT_GPIO_VALUE0);
}
void arduino_contol_1(){
    IoTGpioSetOutputVal(ARDUINO_COM1 , IOT_GPIO_VALUE1);
}
void arduino_contol_2(){
    IoTGpioSetOutputVal(ARDUINO_COM2 , IOT_GPIO_VALUE1);
}

void pump_emmm(uint16_t type){

    IotGpioValue val_pump_in =IOT_GPIO_VALUE0;
    pump_on();
    switch(1){
        case 1:arduino_contol_1();break;
        case 2:arduino_contol_2();break;
        default :break;
    }
    printf("气泵开始运行\n");
    IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
    while(1){
        IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
        if(val_pump_in == IOT_GPIO_VALUE1){
            hi_udelay(50);
            printf("%d\n",val_pump_in);
            IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
            if(val_pump_in == IOT_GPIO_VALUE1){
                break;
            }
        }
    }
    /* do{
        IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
        Tasksleep();
        printf("%d\n",val_pump_in);
    }while(val_pump_in == IOT_GPIO_VALUE0); */
    printf("放下物体\n");
    pump_off();
    pump_contol_on();
    while(1){
        IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
        if(val_pump_in == IOT_GPIO_VALUE0){
            hi_udelay(50);
            IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
            if(val_pump_in == IOT_GPIO_VALUE0){
                break;
            }
        }
    }

    /* do{
        IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
    }while(val_pump_in == IOT_GPIO_VALUE1); */
    pump_contol_off();
    printf("结束放下物体\n");
}
void PumpEntry(uint16_t type)
{
    pump_init();
    IotGpioValue val_pump_in =IOT_GPIO_VALUE0;
    pump_on();
    switch(type){
        case 1:arduino_contol_1();break;
        case 2:arduino_contol_2();break;
        case 3:arduino_contol_3();break;
        default :break;
    }
    printf("气泵开始运行\n");
    IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
    while(1){
        IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
        if(val_pump_in == IOT_GPIO_VALUE1){
            hi_udelay(50);
            printf("%d\n",val_pump_in);
            IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
            if(val_pump_in == IOT_GPIO_VALUE1){
                break;
            }
        }
    }
    /* do{
        IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
        Tasksleep();
        printf("%d\n",val_pump_in);
    }while(val_pump_in == IOT_GPIO_VALUE0); */
    printf("放下物体\n");
    pump_off();
    pump_contol_on();
    while(1){
        IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
        if(val_pump_in == IOT_GPIO_VALUE0){
            hi_udelay(50);
            IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
            if(val_pump_in == IOT_GPIO_VALUE0){
                break;
            }
        }
    }

    /* do{
        IoTGpioGetInputVal(PUMP_IN,&val_pump_in);
    }while(val_pump_in == IOT_GPIO_VALUE1); */
    pump_contol_off();
    printf("结束放下物体\n");
}

/* hi_u32 AppDemoTask(hi_void)
{
    osThreadAttr_t hisignallingAttr = {0};

    hisignallingAttr.stack_size = 4096;
    hisignallingAttr.priority = 25;
    hisignallingAttr.name = (hi_char*)"App_Demo";

    if (osThreadNew((osThreadFunc_t)PumpEntry, NULL, &hisignallingAttr) == NULL) {
        printf("Falied to create uart demo task!\n");
    }
} */
//SYS_RUN(AppDemoTask);
