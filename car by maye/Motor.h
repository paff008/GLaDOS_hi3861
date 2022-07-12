#ifndef __MOTOR_H
#define __MOTOR_H
#include "stm32f10x.h"  

void Motor_Init_Motor1(void);

void Motor_Init_Motor2(void);

void Motor_Init_Motor3(void);

void Motor_Init_Motor4(void);


//左前电机
void Motor_A(int state);


//右后电机
void Motor_B(int state);                    


//左后电机
void Motor_C(int state);                     


//右前电机
void Motor_D(int state);                     


void Motor_SetSpeed_A(int16_t Speed);

void Motor_SetSpeed_B(int16_t Speed);

void Motor_SetSpeed_C(int16_t Speed);

void Motor_SetSpeed_D(int16_t Speed);



#endif

