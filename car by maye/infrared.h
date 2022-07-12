#ifndef __CAR_STATE_H
#define __CAR_STATE_H

#define infrared_PORT GPIOC

#define infrared_RCC RCC_APB2Periph_GPIOC 

#define INFRARED_STATE_1() GPIO_ReadInputDataBit(infrared_PORT,infrared_PIN_1)//������1��״̬
#define INFRARED_STATE_2() GPIO_ReadInputDataBit(infrared_PORT,infrared_PIN_2)//������2��״̬
#define INFRARED_STATE_3() GPIO_ReadInputDataBit(infrared_PORT,infrared_PIN_3)//������3��״̬
#define INFRARED_STATE_4() GPIO_ReadInputDataBit(infrared_PORT,infrared_PIN_4)//������4��״̬
#define INFRARED_STATE_5() GPIO_ReadInputDataBit(infrared_PORT,infrared_PIN_5)//������5��״̬
#define INFRARED_STATE_6() GPIO_ReadInputDataBit(infrared_PORT,infrared_PIN_6)//������6��״̬
#define INFRARED_STATE_7() GPIO_ReadInputDataBit(infrared_PORT,infrared_PIN_7)//������7��״̬
#define INFRARED_STATE_8() GPIO_ReadInputDataBit(infrared_PORT,infrared_PIN_8)//������8��״̬

#define infrared_PIN_1 GPIO_Pin_0
#define infrared_PIN_2 GPIO_Pin_1
#define infrared_PIN_3 GPIO_Pin_2
#define infrared_PIN_4 GPIO_Pin_3
#define infrared_PIN_5 GPIO_Pin_4
#define infrared_PIN_6 GPIO_Pin_5
#define infrared_PIN_7 GPIO_Pin_6
#define infrared_PIN_8 GPIO_Pin_7

void infrared_INIT_1(void);
void infrared_INIT_2(void);
void infrared_INIT_3(void);
void infrared_INIT_4(void);
void infrared_INIT_5(void);
void infrared_INIT_6(void);
void infrared_INIT_7(void);
void infrared_INIT_8(void);


#endif
