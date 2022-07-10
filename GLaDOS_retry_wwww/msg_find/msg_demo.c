#include <stdio.h>
#include <unistd.h>
#include "ohos_init.h"
#include "cmsis_os2.h"
#include "iot_gpio.h"
#include "iot_gpio_ex.h"
#include "range/range_finding.h"
#include "msg_demo.h"
#include "hislink/hisignalling_protocol.h"
#include <uart_stm32/uart_32demo.h>
#include <pump/pump_control.h>

MSG_GLOBAL msg_global;
osMessageQueueId_t msg_form_global;

#define X_MAX 256
#define Y_MAX 256
#define DISTANCE_MIN 10


void MSG_Receive_Demo(){        
        osStatus_t status;
        status = osMessageQueueGet(MSG_Taurus, &msg_taurus, NULL, 0U);   // wait for message
        if (status == osOK) {
            //在这里处理Taurus收到的数据
            printf("数据传输成功，舵机\n");
            msg_global.msg_tower_x =   msg_taurus.buf_x;
            msg_global.msg_tower_y =   msg_taurus.buf_y;
            msg_global.msg_type =  msg_taurus.buf_type;
            printf("收到来自Taurus的数据 %d %d %d \n",msg_global.msg_tower_x,msg_global.msg_tower_y,msg_global.msg_type);
        }
        /* status = osMessageQueueGet(mid_MagRange, &meg_range,  NULL, 0U);        //此功能与app_demo_config中重复
        printf("DEMO complete");
        if (status == osOK) {
            msg_global.meg_distance =meg_range.meg_distance;
            printf("distance:%f\n",msg_global.meg_distance);
        } */
}
void MSG_Transmit_Demo(){
    //printf("处理模块开始执行");
    MOVE_TYPE move_type = NULL_TYPE;
    if(msg_global.msg_type != NULL){
        if((msg_global.msg_tower_x>0)&&(msg_global.msg_tower_x<X_MAX)&&(msg_global.msg_tower_y>0)&&(msg_global.msg_tower_y<Y_MAX)){
            if(msg_global.msg_tower_x<(int)((float)X_MAX*0.4)){
                move_type = TURN_LEFT;
            }else if(msg_global.msg_tower_x>(int)((float)X_MAX*0.6)){
                move_type = TURN_RIGHT;
            }else{
                move_type = GO_STRAIGHT;
            }
        }else{
            printf("位置出错,检查下");
        }
    }else{
        //向下位机发送自动瞎跑模式
        printf("瞎跑什么呢 \n");
        UART_Send_32(UART_XiaRun);
    }
    switch(move_type){
        case (TURN_LEFT):
            if((msg_global.meg_distance>0)&&(msg_global.meg_distance <= DISTANCE_MIN)){
                //向下位机发送向左的指令
                printf("往左啊笨比 \n");
                UART_Send_32(UART_TURN_LEFT);
            }else{
                //向下位机发送向左前的指令
                printf("往左前啊笨比 \n");
                UART_Send_32(UART_TURN_FRONT_LEFT);
            }
        break;
        case (GO_STRAIGHT):
            if((msg_global.meg_distance>0)&&(msg_global.meg_distance <= DISTANCE_MIN)){
                //向下位机发送抓取和停止指令  //待定
                for(int i=0;i<=9;i++){
                    UART_Send_32(UART_STOP);
                    printf("站住笨比 \n");
                }
                printf("站住笨比 \n");
                pump_emmm(msg_global.msg_type);
            }else{
                //向下位机发送向前的指令
                printf("往前啊笨比 \n");
                UART_Send_32(UART_GO_STRAIGHT);
            }
        break;
        case (TURN_RIGHT):
            if((msg_global.meg_distance>0)&&(msg_global.meg_distance <= DISTANCE_MIN)){
                //向下位机发送向右的指令
                printf("往右啊笨比 \n");
                UART_Send_32(UART_TURN_RIGHT);
            }else{
                //向下位机发送向右前的指令
                printf("往右前啊笨比 \n");
                UART_Send_32(UART_TURN_FRONT_RIGHT);
            }
        break;
        default:printf("移动模式出错");
    }
    return;
}

static void *demo_ha(const void *arg){
    (void)arg;
    osStatus_t status;
    while(1){
        status = osMessageQueueGet(msg_form_global, &msg_global, NULL, 0U);
        printf("DEMO complete");
        if (status == osOK) {
            
        }
    }
    hi_udelay(1000000);
}
