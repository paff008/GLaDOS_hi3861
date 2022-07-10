/*
 * Copyright (c) 2022 HiSilicon (Shanghai) Technologies CO., LIMITED.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//#include <hi_task.h>
#include <string.h>
#include <hi_wifi_api.h>
#include <hi_mux.h>
#include <hi_io.h>
#include "iot_gpio_ex.h" 
#include <hi_gpio.h>
#include "iot_config.h"
#include "iot_log.h"
#include "iot_main.h"
#include "iot_profile.h"
#include "ohos_init.h"
#include "cmsis_os2.h"
#include "msg_find/msg_demo.h"
#include "oled/oled_demo.h"

/* attribute initiative to report */
#define TAKE_THE_INITIATIVE_TO_REPORT
#define ONE_SECOND                          (1000)
/* oc request id */
#define CN_COMMADN_INDEX                    "commands/request_id="
/* #define WECHAT_SUBSCRIBE_LIGHT           "light"
#define WECHAT_SUBSCRIBE_LIGHT_ON_STATE     "1"
#define WECHAT_SUBSCRIBE_LIGHT_OFF_STATE    "0"
#define WECHAT_SUBSCRIBE_Tower              "tower"
#define WECHAT_SUBSCRIBE_Tower_ON_RST       "1"
#define WECHAT_SUBSCRIBE_Tower_OFF_RST      "0" */

#define WECHAT_SUBSCRIBE_CONTROL          "control"
#define WECHAT_SUBSCRIBE_CONTROL_AUTO     "0"
#define WECHAT_SUBSCRIBE_CONTROL_HUMAN    "2"
#define WECHAT_SUBSCRIBE_MOVE             "move"

#define WECHAT_SUBSCRIBE_MOVE1             "move1"
#define WECHAT_SUBSCRIBE_MOVE2             "move2"
#define WECHAT_SUBSCRIBE_MOVE3             "move3"

#define WECHAT_SUBSCRIBE_MOVE_TYPE0       "0"
#define WECHAT_SUBSCRIBE_MOVE_TYPE1       "1"
#define WECHAT_SUBSCRIBE_MOVE_TYPE2       "2"



osMessageQueueId_t mutex_id;
extern osMutexId_t msg_form_global;

//int g_ligthStatus = -1;
//int g_towerStatus = -1;

int g_controlStatus = -1;
int g_moveStatus = -1;

typedef void (*FnMsgCallBack)(hi_gpio_value val);

typedef struct FunctionCallback {
    hi_bool  stop;
    hi_u32 conLost;
    hi_u32 queueID;
    hi_u32 iotTaskID;
    FnMsgCallBack    msgCallBack;
}FunctionCallback;
FunctionCallback g_functinoCallback;

// CPU Sleep time Set            //与hal_iot_gpio_ex.c中定义重复
/* unsigned int TaskMsleep(unsigned int ms)
{
    if (ms <= 0) {
        return HI_ERR_FAILURE;
    }
    return hi_sleep((hi_u32)ms);
} */

uint8_t dedede =1;

static void DeviceConfigInit(hi_gpio_value val)
{
    hi_io_set_func(HI_IO_NAME_GPIO_9, HI_IO_FUNC_GPIO_9_GPIO);
    hi_gpio_set_dir(HI_GPIO_IDX_9, HI_GPIO_DIR_OUT);
    hi_gpio_set_ouput_val(HI_GPIO_IDX_9, val);
}

static int  DeviceMsgCallback(FnMsgCallBack msgCallBack)
{
    g_functinoCallback.msgCallBack = msgCallBack;
    return 0;
}

static void wechatControlDeviceMsg(hi_gpio_value val)
{
    DeviceConfigInit(val);
}

// < this is the callback function, set to the mqtt, and if any messages come, it will be called
// < The payload here is the json string
static void DemoMsgRcvCallBack(int qos, const char *topic, const char *payload)
{
    IOT_LOG_DEBUG("RCVMSG:QOS:%d TOPIC:%s PAYLOAD:%s\r\n", qos, topic, payload);
    /* 云端下发命令后，板端的操作处理 */
    if (strstr(payload, WECHAT_SUBSCRIBE_CONTROL) != NULL) {
        if (strstr(payload, WECHAT_SUBSCRIBE_CONTROL_AUTO) != NULL) {
            //wechatControlDeviceMsg(HI_GPIO_VALUE1);
            printf("收到来自天堂的消息 让你选择自动模式\n");
            g_controlStatus = 0;
        } else if(strstr(payload, WECHAT_SUBSCRIBE_CONTROL_HUMAN) != NULL) {
            //wechatControlDeviceMsg(HI_GPIO_VALUE0);
            printf("收到来自天堂的消息 让你选择自动模式\n");
            g_controlStatus = 1;
        } else{
            printf("模式控制命令下发出错\n");
        }
    }
        if (strstr(payload, WECHAT_SUBSCRIBE_MOVE1) != NULL) {
            //wechatControlDeviceMsg(HI_GPIO_VALUE1);
            printf("收到来自天堂的消息 你选择了模式114514\n");
            g_moveStatus = 0;
        } else if(strstr(payload, WECHAT_SUBSCRIBE_MOVE2) != NULL){
            //wechatControlDeviceMsg(HI_GPIO_VALUE0);
            printf("收到来自天堂的消息 你选择了模式一\n");
            g_moveStatus = 1;
        } else if(strstr(payload, WECHAT_SUBSCRIBE_MOVE3) != NULL){
            //wechatControlDeviceMsg(HI_GPIO_VALUE0);
            printf("收到来自天堂的消息 你选择了模式二\n");
            g_moveStatus = 2;
        } else{
            printf("移动命令下发出错\n");
        }
    //这里需要添加一个判断，只有在人干预的模式下才会执行
    /* if(strstr(payload, WECHAT_SUBSCRIBE_MOVE) != NULL){
        if (strstr(payload, WECHAT_SUBSCRIBE_MOVE_TYPE0) != NULL) {
            //wechatControlDeviceMsg(HI_GPIO_VALUE1);
            printf("收到来自天堂的消息 你选择了模式114514\n");
            g_moveStatus = 0;
        } else if(strstr(payload, WECHAT_SUBSCRIBE_MOVE_TYPE1) != NULL){
            //wechatControlDeviceMsg(HI_GPIO_VALUE0);
            printf("收到来自天堂的消息 你选择了模式一\n");
            g_moveStatus = 1;
        } else if(strstr(payload, WECHAT_SUBSCRIBE_MOVE_TYPE2) != NULL){
            //wechatControlDeviceMsg(HI_GPIO_VALUE0);
            printf("收到来自天堂的消息 你选择了模式二\n");
            g_moveStatus = 2;
        } else{
            printf("移动命令下发出错\n");
        }
    } */
    return HI_NULL;
}

/* publish sample */
hi_void IotPublishSample(void)
{
    /* reported attribute */
    WeChatProfile weChatProfile = {
        .subscribeType = "type",
        .status.subState = "state",
        .status.subReport = "reported",
        .status.reportVersion = "version",
        .status.Token = "clientToken",
        /* report motor */
        /* .reportAction.subDeviceActionMotor = "motor",

        .reportAction.subDeviceActionTemperature = "temperature",
        .reportAction.temperatureData = 30, // 30 :temperature data 
        // report humidity 
        .reportAction.subDeviceActionHumidity = "humidity",
        .reportAction.humidityActionData = 55, // humidity data
        // report light_intensity 
        .reportAction.subDeviceActionLightIntensity = "light_intensity",
        .reportAction.lightIntensityActionData = 60, // 60 : light_intensity */
        
        .reportAction.subDeviceActionMoveType = "movetype",         //移动模式
        .reportAction.moveTypeData =msg_global.move_data,
        .reportAction.subDeviceActionRubbishType = "rubbishtype",   //垃圾类型
        .reportAction.rubbishTypeData =msg_global.msg_type,
        .reportAction.subDeviceActionDistance = "distance",         //距离
        .reportAction.distanceData =msg_global.meg_distance, 
        .reportAction.subDeviceActionError = "error",         //错误
        .reportAction.errorData =msg_global.error_data, 


    };

    /* report light */
    if (g_controlStatus == 0) {
        weChatProfile.reportAction.subDeviceActionControlStatus = "control";
        weChatProfile.reportAction.controlActionStatus = 0; 
    }else if (g_controlStatus == 1) {
        weChatProfile.reportAction.subDeviceActionControlStatus = "control";
        weChatProfile.reportAction.controlActionStatus = 1; 
    }else {
        weChatProfile.reportAction.subDeviceActionControlStatus = "control";
        weChatProfile.reportAction.controlActionStatus = 0; 
    }
    /* report tower */
    if (g_moveStatus == 0) {
        weChatProfile.reportAction.subDeviceActionMoveStatus = "move";
        weChatProfile.reportAction.moveActionStatus = 0; /* 1: tower on */
    } else if (g_moveStatus == 1) {
        weChatProfile.reportAction.subDeviceActionMoveStatus = "move";
        weChatProfile.reportAction.moveActionStatus = 1; /* 0: tower off */
    } else if (g_moveStatus == 2) {
        weChatProfile.reportAction.subDeviceActionMoveStatus = "move";
        weChatProfile.reportAction.moveActionStatus = 2; /* 0: tower off */
    } else {
        weChatProfile.reportAction.subDeviceActionMoveStatus = "move";
        weChatProfile.reportAction.moveActionStatus = 0; /* 0: tower off */
    }
    /* profile report */
    IoTProfilePropertyReport(CONFIG_USER_ID, &weChatProfile);
}

// < this is the demo main task entry,here we will set the wifi/cjson/mqtt ready and
// < wait if any work to do in the while
static hi_void *DemoEntry(const char *arg)
{
    hi_watchdog_disable();
    printf("看门狗关闭函数\n");
    IoTSetMsgCallback(DemoMsgRcvCallBack);
    printf("设置回报函数\n");
    WifiStaReadyWait();
    printf("wifi准备完毕\n");
    cJsonInit();
    printf("cjson初始化完毕\n");
    IoTMain();
    printf("iotmain 执行\n");
    /* 云端下发回调 */
    IoTSetMsgCallback(DemoMsgRcvCallBack);
    printf("设置回报函数\n");
    /* if(dedede == 1){
        printf_failure();
        dedede = 0;
    } */
    /* 主动上报 */
#ifdef TAKE_THE_INITIATIVE_TO_REPORT
    while (1) {
        printf("申请互斥锁\n");
        osMutexAcquire(mutex_id, osWaitForever);
        printf("申请互斥锁成功\n");        
        // 用户可以在这调用发布函数进行发布，需要用户自己写调用函数 
        IotPublishSample(); // 发布例程
        printf("发布例程\n");
#endif
        TaskMsleep(500);
        printf("延时500ms 成功\n");
    }
    return NULL;
}

// < This is the demo entry, we create a task here,
// and all the works has been done in the demo_entry
#define CN_IOT_TASK_STACKSIZE  0x1000
#define CN_IOT_TASK_PRIOR 25
#define CN_IOT_TASK_NAME "IOTDEMO"

static void AppDemoIot(void)
{
    osThreadAttr_t attr;
    IoTWatchDogDisable();

    attr.name = "IOTDEMO";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = CN_IOT_TASK_STACKSIZE;
    attr.priority = CN_IOT_TASK_PRIOR;

    if (osThreadNew((osThreadFunc_t)DemoEntry, NULL, &attr) == NULL) {
        printf("[mqtt] Falied to create IOTDEMO!\n");
    }
}

SYS_RUN(AppDemoIot);
