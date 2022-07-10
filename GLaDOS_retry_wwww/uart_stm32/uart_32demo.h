#ifndef _UART_DEMO32_H
#define _UART_DEMO32_H

typedef enum{
    UART_TURN_LEFT = 0,
    UART_TURN_FRONT_LEFT,
    UART_GO_STRAIGHT = 2,
    UART_TURN_FRONT_RIGHT,
    UART_TURN_RIGHT = 4,
    UART_STOP,
    UART_XiaRun
}UART_MSG_TYPE;
static const uint8_t *uart_data[7] ={"0x12","0x34","0x56","0x78","0x9a","0xab","0xbc"};
static const char *uart_recceive = "hello_pegasus";
static const uint8_t *uart_data_cheak = "0x14";
void UART_Send_32(UART_MSG_TYPE type);

#endif 
