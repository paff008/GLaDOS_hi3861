#ifndef MSG_GLABAL_H
#define MSG_GLABAL_H

#include "ohos_init.h"
#include "cmsis_os2.h"


typedef struct{
    uint16_t msg_tower_x;
    uint16_t msg_tower_y;
    uint16_t msg_type;            //垃圾类型数据（上报）
    float meg_distance;           //距离(上报)
    uint16_t contorl_model;       //控制模式数据（接收）
    uint16_t move_model;          //移动模式_人工（接收）
    uint16_t error_data;          //错判类型(上报)
    uint16_t move_data;           //移动数据（上报）
}MSG_GLOBAL;

typedef enum {
    NULL_TYPE = 0,
    TURN_LEFT,
    GO_STRAIGHT,
    TURN_RIGHT
}MOVE_TYPE;
extern MSG_GLOBAL msg_global;
extern osMutexId_t msg_form_global;

extern osMessageQueueId_t mutex_id;

void MSG_Receive_Demo(void);
void MSG_Transmit_Demo(void);

//void UART_Send(UART_MSG_TYPE type);
#endif
