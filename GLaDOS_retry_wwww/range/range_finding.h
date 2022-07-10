#ifndef HCSR04_H
#define HCSR04_H

#include <stdio.h>
#include <unistd.h>
#include "ohos_init.h"
#include "cmsis_os2.h"
#include "iot_gpio.h"
#include "iot_gpio_ex.h"

//超声波模块引脚定义  
#define TRIG_PIN IOT_IO_NAME_GPIO_11
#define ECHO_PIN IOT_IO_NAME_GPIO_12

typedef struct{
    float meg_distance;
}MSG_RANGE;

extern MSG_RANGE meg_range;
extern osMessageQueueId_t mid_MagRange;

void sr04_init(void);         //超声波模块初始化函数

float sr04_get_distance(void);  //超声波模块测距

#endif
