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
 
#include <hi_stdlib.h>
#include "hisignalling_protocol.h"
#include "hi_uart.h"
#include "app_demo_uart.h"
#include <iot_uart.h>
#include <hi_gpio.h>
#include <hi_io.h>
#include "iot_gpio_ex.h"
#include "ohos_init.h"
#include "cmsis_os2.h"
//#include "msg_find/msg_demo.h"

UartDefConfig uartDefConfig = {0};

static void Uart1GpioCOnfig(void)
{
#ifdef ROBOT_BOARD
    IoSetFunc(HI_IO_NAME_GPIO_5, IOT_IO_FUNC_GPIO_5_UART1_RXD);
    IoSetFunc(HI_IO_NAME_GPIO_6, IOT_IO_FUNC_GPIO_6_UART1_TXD);
    /* IOT_BOARD */
#elif defined (EXPANSION_BOARD)
    IoSetFunc(HI_IO_NAME_GPIO_0, IOT_IO_FUNC_GPIO_0_UART1_TXD);
    IoSetFunc(HI_IO_NAME_GPIO_1, IOT_IO_FUNC_GPIO_1_UART1_RXD);
#endif
}

int SetUartRecvFlag(UartRecvDef def)
{
    if (def == UART_RECV_TRUE) {
        uartDefConfig.g_uartReceiveFlag = HI_TRUE;
    } else {
        uartDefConfig.g_uartReceiveFlag = HI_FALSE;
    }
    
    return uartDefConfig.g_uartReceiveFlag;
}

int GetUartConfig(UartDefType type)
{
    int receive = 0;

    switch (type) {
        case UART_RECEIVE_FLAG:
            receive = uartDefConfig.g_uartReceiveFlag;
            break;
        case UART_RECVIVE_LEN:
            receive = uartDefConfig.g_uartLen;
            break;
        default:
            break;
    }
    return receive;
}

void ResetUartReceiveMsg(void)
{
    (void)memset_s(uartDefConfig.g_receiveUartBuff, sizeof(uartDefConfig.g_receiveUartBuff),
        0x0, sizeof(uartDefConfig.g_receiveUartBuff));
}

unsigned char *GetUartReceiveMsg(void)
{
    return uartDefConfig.g_receiveUartBuff;
}

hi_void uart1_taurus_init(void){
    hi_u32 ret = 0;
    IotUartAttribute uartAttr = {
        .baudRate = 115200, /* baudRate: 115200 */
        .dataBits = 8, /* dataBits: 8bits */
        .stopBits = 1, /* stop bit */
        .parity = 0,
    };
    /* Initialize uart driver */
    ret = IoTUartInit(DEMO_UART_NUM, &uartAttr);
    if (ret != HI_ERR_SUCCESS) {                       //这里可能报错，删掉这就行
        printf("Failed to init uart! Err code = %d\n", ret);
    }
}

hi_void *UartDemoTask(void)     //char *param
{
    //int demo = rand()%5;
    //int demo = 1;
    /* hi_u8 uartBuff[UART_BUFF_SIZE]= {0xaa, 0x55, 0x00, 0x02, 0x03, 0x01, 0xff,0x8e,0xd2,0xbe,0xdf};
    switch(demo){
        case 0:uartBuff[3]= 0x02; uartBuff[4]= 0x03; uartBuff[5]= 0x01;break;
        case 1:uartBuff[3]= 0xff; uartBuff[4]= 0x03; uartBuff[5]= 0x02;break;
        case 2:uartBuff[3]= 0x02; uartBuff[4]= 0xff; uartBuff[5]= 0x03;break;
        case 3:uartBuff[3]= 0xff; uartBuff[4]= 0xff; uartBuff[5]= 0x04;break;
        case 4:uartBuff[3]= 0x99; uartBuff[4]= 0x99; uartBuff[5]= 0x05;break;
    } */

    //hi_u8 uartBuff[UART_BUFF_SIZE] = {0xaa, 0x55, 0x00, 0x02, 0x03, 0x01, 0xff,0x8e,0xd2,0xbe,0xdf}; //这是测试
    hi_u8 uartBuff_last[UART_BUFF_SIZE]={0xaa, 0x55, 0x00, 0x02, 0x03, 0x01, 0xff,0x8e,0xd2,0xbe,0xdf};
    hi_u8 uartBuff1[UART_BUFF_SIZE] ={0};
    hi_u8 uart_nmd[1]={0Xaa};
    //hi_unref_param(param);
    Uart1GpioCOnfig();
    for (int j=0;j<12;j++) {
        IoTUartRead(DEMO_UART_NUM, uart_nmd, 1);
        if(uart_nmd[0] == 0xaa){
            uartDefConfig.g_uartLen = IoTUartRead(DEMO_UART_NUM, uartBuff1, 11);        
            uartDefConfig.g_uartLen =  11; //这是我写的测试

            //这里是家的：：：
                hi_u8 uartBuff1[UART_BUFF_SIZE] ={0x55};
            if ((uartDefConfig.g_uartLen > 0)&& (uartBuff1[0] == 0x55)) {   // && (uartBuff1[0] == 0xaa) && (uartBuff1[1] == 0x55)            
                printf("读取到了！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");            
                if (GetUartConfig(UART_RECEIVE_FLAG) == HI_FALSE) {

                    (void)memcpy_s(uartDefConfig.g_receiveUartBuff, uartDefConfig.g_uartLen,                    
                        uartBuff_last, uartDefConfig.g_uartLen);                
                    (void)SetUartRecvFlag(UART_RECV_TRUE);                
                    break;
                }
            }
        }
        printf("uart1 读取函数启动\n");
        /* uartDefConfig.g_uartLen = IoTUartRead(DEMO_UART_NUM, uartBuff1, 11);
        uartDefConfig.g_uartLen =  11; //这是我写的测试
        if ((uartDefConfig.g_uartLen > 0)) {// && (uartBuff1[0] == 0xaa) && (uartBuff1[1] == 0x55)
            printf("读取到了！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
            if (GetUartConfig(UART_RECEIVE_FLAG) == HI_FALSE) {
                (void)memcpy_s(uartDefConfig.g_receiveUartBuff, uartDefConfig.g_uartLen,
                    uartBuff1, uartDefConfig.g_uartLen);
                (void)SetUartRecvFlag(UART_RECV_TRUE);
                break;
            }
        } */
        //printf("uart1 读取函数启动\n");
        //TaskMsleep(30); /* 20:sleep 20ms */
    }
    return HI_NULL;
}

/*
 * This demo simply shows how to read datas from UART2 port and then echo back.
 */
hi_void UartTransmit(hi_void){
    hi_u32 ret = 0;
    IotUartAttribute uartAttr = {
        .baudRate = 115200, /* baudRate: 115200 */
        .dataBits = 8, /* dataBits: 8bits */
        .stopBits = 1, /* stop bit */
        .parity = 0,
    };
    /* Initialize uart driver */
    ret = IoTUartInit(DEMO_UART_NUM, &uartAttr);
    if (ret != HI_ERR_SUCCESS) {                       //这里可能报错，删掉这就行
        printf("Failed to init uart!  这里是和上位机Err code = %d\n", ret);
    }
    /* Create a task to handle uart communication */
    osThreadAttr_t attr = {0};
    attr.stack_size = UART_DEMO_TASK_STAK_SIZE;
    attr.priority = UART_DEMO_TASK_PRIORITY;
    attr.name = (hi_char*)"uart demo";
    if (osThreadNew((osThreadFunc_t)UartDemoTask, NULL, &attr) == NULL) {
        printf("Falied to create uart demo task!\n");
    }
}
//SYS_RUN(UartTransmit);
