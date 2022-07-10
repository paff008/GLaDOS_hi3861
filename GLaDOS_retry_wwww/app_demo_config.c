#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include "ohos_init.h"
#include "cmsis_os2.h"
#include "iot_i2c.h"
#include "iot_gpio.h"
#include "iot_gpio_ex.h"
#include "iot_uart.h"
#include "hi_uart.h"

#include "app_demo_config.h"
#include "msg_find/msg_demo.h"

#include "hislink/app_demo_uart.h"
#include "hislink/hisignalling_protocol.h"
#include "tower/tower.h"
#include "range/range_finding.h"
#include "hi_timer.h"
#include "oled/oled_fonts.h"
#include "oled/oled_demo.h"

#include "iot_errno.h"
#include "oled/oled_ssd1306.h"

#define KEY_S1 5
#define KEY_S2 8



uint8_t config_control_type = 0x00;

uint32_t callback1, callback2, callback3;
extern osMessageQueueId_t mutex_id;


/* void key_gpio_init(){
    IoTGpioInit(KEY_S1);
    IoSetFunc(KEY_S1,IOT_IO_FUNC_GPIO_5_GPIO);
    IoTGpioSetDir(KEY_S1,IOT_GPIO_DIR_IN);
    IoSetPull(KEY_S1,IOT_IO_PULL_UP);
    IoTGpioRegisterIsrFunc(KEY_S1,IOT_INT_TYPE_EDGE,IOT_GPIO_EDGE_FALL_LEVEL_LOW,keyS1_CallbackFunc,NULL);

    IoTGpioInit(KEY_S2);
    IoSetFunc(KEY_S2,IOT_IO_FUNC_GPIO_5_GPIO);
    IoTGpioSetDir(KEY_S2,IOT_GPIO_DIR_IN);
    IoSetPull(KEY_S2,IOT_IO_PULL_UP);
    IoTGpioRegisterIsrFunc(KEY_S2,IOT_INT_TYPE_EDGE,IOT_GPIO_EDGE_FALL_LEVEL_LOW,keyS2_CallbackFunc,NULL);
} */

void Tower_Range_Demo(MSG_GLOBAL msg){   //舵机和测距模块控制执行
    TOWER_CONFIG tower;
    tower.Tower_x = msg.msg_tower_x;
    tower.Tower_y = msg.msg_tower_y;
    sr04_init();       
    Tower_init();
    msg.meg_distance = sr04_get_distance();
    if((msg.meg_distance <0)&&(msg.meg_distance >1000)){
        msg.meg_distance = 114514;
    }
    msg_global.meg_distance = msg.meg_distance;
    tower_control(tower);
}

/* static void *App_Demo(const void *arg){
    (void)arg;
    while(1){
        printf("任务 app_demo_config  假装执行\n");
        MSG_Receive_Demo();
        printf("任务 app_demo_config  1 执行\n");
        Tower_Range_Demo(msg_global);
        printf("任务 app_demo_config 2  执行\n");
        MSG_Transmit_Demo();
        printf("任务 app_demo_config 执行\n");
        TaskMsleep(500);
    }
} */

void Timer1Callback(void *arg){
    (void)arg;

    printf("回调函数一开始执行\n");
    //printf_science();
    pump_init();
    uart1_taurus_init();
    UartDemoTask();
    TaskMsleep(50);
    printf("回调函数一执行\n");

}
void Timer2Callback(void *arg){
    printf("回调函数二开始执行\n");
    (void)arg;
    HisignallingMsgHandle();
    TaskMsleep(50);
    printf("回调函数二执行\n");
}
void Timer3Callback(void *arg){
    printf("回调函数三开始执行\n");
    (void)arg;
    MSG_Receive_Demo();
    Tower_Range_Demo(msg_global);
    MSG_Transmit_Demo();
    TaskMsleep(50);
    printf("回调函数三执行\n");
}
void SoftwareTimersTaskEntry(void)
{
    osMutexAcquire(mutex_id, osWaitForever);
    osTimerId_t callback_id1, callback_id2,callback_id3;
    uint32_t timerDelay;
    osStatus_t status;
    
    if(dededa == 1){
        oled_init_demo();
        dededa = 0;
        printf_science();
    }
    callback1 = 1U;
    callback_id1 = osTimerNew(Timer1Callback, osTimerPeriodic, &callback1, NULL);
    if (callback_id1 != NULL)
    {
        // Hi3861 1U=10ms,100U=1S
        timerDelay = 50U;
        status = osTimerStart(callback_id1, timerDelay);
        if (status != osOK)
        {
            // Timer could not be started
            printf("回调函数1启动失败");
        }
    }
    callback2 = 1U;
    callback_id2 = osTimerNew(Timer2Callback, osTimerPeriodic, &callback2, NULL);
    if (callback_id2 != NULL)
    {
        // Hi3861 1U=10ms,100U=1S
        timerDelay = 50U;
        status = osTimerStart(callback_id2, timerDelay);
        if (status != osOK)
        {
            // Timer could not be started
            printf("回调函数2启动失败");
        }
    }
    callback3 = 1U;
    callback_id3 = osTimerNew(Timer3Callback, osTimerPeriodic, &callback3, NULL);
    if (callback_id3 != NULL)
    {
        // Hi3861 1U=10ms,100U=1S
        timerDelay = 50U;
        status = osTimerStart(callback_id3, timerDelay);
        if (status != osOK)
        {
            // Timer could not be started
            printf("回调函数3启动失败");
        }
    }
    osMutexRelease(mutex_id);
}

hi_u32 AppDemoTask(hi_void)
{
    MSG_Taurus = osMessageQueueNew(2, 100, NULL);
    if (MSG_Taurus == NULL) {
        printf("Falied to create Message Queue!\n");
    } 
    hi_u32 ret = 0;
    osThreadAttr_t hisignallingAttr = {0};

    hisignallingAttr.stack_size = 4096;
    hisignallingAttr.priority = 25;
    hisignallingAttr.name = (hi_char*)"App_Demo";

    if (osThreadNew((osThreadFunc_t)SoftwareTimersTaskEntry, NULL, &hisignallingAttr) == NULL) {
        HISIGNALLING_LOG_ERROR("Failed to create hisignaling msg task\r\n");
        return HI_ERR_FAILURE;
    }
    return HI_ERR_SUCCESS;
}

SYS_RUN(AppDemoTask);
