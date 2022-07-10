#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "ohos_init.h"
#include "cmsis_os2.h"
#include <hi_gpio.h>
#include <hi_io.h>
#include "iot_gpio_ex.h"
#include <hi_stdlib.h>
#include "hi_uart.h"
#include "iot_gpio.h"
#include "uart_32demo.h"
#include <hislink/app_demo_uart.h>

static hi_u8 uart_data_1[1] = {0x12};
static hi_u8 uart_data_2[1] = {0x34};
static hi_u8 uart_data_3[1] = {0x56};
static hi_u8 uart_data_4[1] = {0x78};
static hi_u8 uart_data_5[1] = {0x9a};
static hi_u8 uart_data_6[1] = {0xbc};
static hi_u8 uart_data_7[1] = {0xde};

#define UART_TASK_STACK_SIZE 1024 * 8
#define UART_TASK_PRIO 25
#define UART_BUFF_SIZE 1000

void UART_Send_32(UART_MSG_TYPE type){
    IoSetFunc(HI_IO_NAME_GPIO_0, IOT_IO_FUNC_GPIO_0_UART1_TXD);
    IoSetFunc(HI_IO_NAME_GPIO_1, IOT_IO_FUNC_GPIO_1_UART1_RXD);
    /* IoSetFunc(HI_IO_NAME_GPIO_5, IOT_IO_FUNC_GPIO_5_UART1_RXD);
    IoSetFunc(HI_IO_NAME_GPIO_6, IOT_IO_FUNC_GPIO_6_UART1_TXD);
 */
    uint8_t uart_buff[UART_BUFF_SIZE] = {0};
    uint8_t *uart_buff_ptr = uart_buff;
    uint32_t len;
    uint32_t ret;

     // 这部分代码为UART初始化的代码，首先要在uart_attr结构体这配置波特率、数据位、停止位、奇偶检验位，然后通过UartInit()函数对串口1进行配置。
    hi_uart_attribute uart_attr = {
        .baud_rate = 115200,
        .data_bits = 8,
        .stop_bits = 1,
        .parity = 0,
        .pad = 0
    };
    //Initialize uart driver
    ret = IoTUartInit(HI_UART_IDX_1, &uart_attr, NULL);
    if (ret != HI_ERR_SUCCESS)
    {
        printf("Failed to init uart! Err code = %d\n", ret);
    }
    printf("UART Test Start\n");
    printf("type %d\n",type);
    //通过串口1发送数据
    //IoTUartWrite(HI_UART_IDX_1, uart_data514, 1);
    //IoTUartWrite(HI_UART_IDX_1, uart_data114[type], 1);
    for(int i=0;i<3;i++){
        switch (type){
            case 1:IoTUartWrite(HI_UART_IDX_1, uart_data_1, 1);break;
            case 2:IoTUartWrite(HI_UART_IDX_1, uart_data_2, 1);break;
            case 3:IoTUartWrite(HI_UART_IDX_1, uart_data_3, 1);break;
            case 4:IoTUartWrite(HI_UART_IDX_1, uart_data_4, 1);break;
            case 5:IoTUartWrite(HI_UART_IDX_1, uart_data_5, 1);break;
            case 6:IoTUartWrite(HI_UART_IDX_1, uart_data_6, 1);break;
            case 7:IoTUartWrite(HI_UART_IDX_1, uart_data_7, 1);break;
        }
    }

    //printf("Uart1 send data:%x\n", uart_data114[type]);
    //通过串口1接收数据
    //IoTUartRead(HI_UART_IDX_1, uart_buff_ptr, 8);

    //printf("Uart1 read data:%s\n", uart_buff_ptr);
    /* if(!strcmp(uart_buff_ptr,uart_data[type])){
        printf("uart for stm 发送成功\n");
    }else{
        printf("uart for stm 发送失败\n");
    } */
}

static void UART_Task(void)
{
   while(1){
       UART_Send_32(UART_TURN_FRONT_LEFT);
   }
}
static void UART_ExampleEntry(void)
{

    osThreadAttr_t attr;

    attr.name = "UART_Task";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = UART_TASK_STACK_SIZE;
    attr.priority = UART_TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)UART_Task, NULL, &attr) == NULL)
    {
        printf("[ADCExample] Falied to create UART_Task!\n");
    }
}

//APP_FEATURE_INIT(UART_ExampleEntry);
