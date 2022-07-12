#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "Delay.h"
#include "LED.h"
#include "infrared.h"
#include "Car_State.h"
#include "usar.h"
#include "stdio.h"
#include "PWM.h"
#include "stdio.h"

int demo = 4;
void USART1_IRQHandler(void);
void EXTI1_IRQHandler(void);
void zhuangtai(void);

void delay(uint16_t time)
{
	uint16_t i =0;
	while(time--){
		i=12000;
		while(i--);
	}
}

int main(void)
{
	//≥ı ºªØ
	/**********************************/
	
	usart_init();
	
	PWM_Init();
	
	LED_Init();
	
	infrared_INIT_1();
	infrared_INIT_2();
	infrared_INIT_3();
	infrared_INIT_4();
	infrared_INIT_5();
	infrared_INIT_6();
	infrared_INIT_7();
	infrared_INIT_8();
	
	Motor_Init_Motor1();
	Motor_Init_Motor2();
	Motor_Init_Motor3();
	Motor_Init_Motor4();
	
	/**********************************/





	/************************************/
	while(1)
	{
		USART1_IRQHandler();
		
	}
	
/**************************************************/
//		 
//		 «∞»˝			1 2 3
//		 ◊Û”“			4 5
//		 ∫Û»˝			6 7 8
}


void USART1_IRQHandler(void)
{
	uint16_t temp;
	
	if(USART_GetITStatus(USART1,USART_IT_RXNE) != RESET){
		
		temp = USART_ReceiveData(USART1);
		
		if(temp == 0x12){
		
			usartSendStr(USART1,"LeftQ45\r\n");
			Car_LeftQ45();
		}
		if(temp == 0x34){
		
			usartSendStr(USART1,"Go\r\n");
			Car_Go();
		}
		if(temp == 0x56){
		
			usartSendStr(USART1,"RightQ45\r\n");
			Car_RightQ45();
		}
		if(temp == 0x78){
		
			//usartSendStr(USART1,"Right\r\n");
			
		}
		if(temp == 0x9a){
		
			usartSendStr(USART1,"Stop\r\n");
			Car_Stop();
		}
		if(temp == 0xbc){
		
			usartSendStr(USART1,"Go\r\n");
			Car_Back();
		}	
	}
}


void zhuangtai(void)
{
		if(INFRARED_STATE_1()==0)			//¡¡µ∆∑µªÿ0 ”–’œ∞≠ŒÔ¡¡µ∆
		 {
			  Car_Back();
			  delay(1000);
				Car_Stop();
				delay(1000);
				Car_RightH45();
				delay(1000);
			  Car_Go();	
			  delay(1000);
		 }
		 

		 
		 else if(INFRARED_STATE_2()==0)			//¡¡µ∆∑µªÿ0 ”–’œ∞≠ŒÔ¡¡µ∆
		 {
				Car_Back();
			  delay(1000);
				Car_Stop();
				delay(1000);
				Car_RightH45();
				delay(1000);
			  Car_Go();
			  delay(1000);
		 }
		 
		 
		 else if(INFRARED_STATE_3()==0)			//¡¡µ∆∑µªÿ0 ”–’œ∞≠ŒÔ¡¡µ∆
		 {
				Car_Back();
			  delay(1000);
				Car_Stop();
				delay(1000);
				Car_LeftH45();
				delay(1000);
			  Car_Go();
			  delay(1000);
		 }
		 
		 
		 else if(INFRARED_STATE_4()==0)			//¡¡µ∆∑µªÿ0 ”–’œ∞≠ŒÔ¡¡µ∆
		 {
				Car_Back();
			  delay(1000);
				Car_Stop();
				delay(1000);
				Car_RightH45();
				delay(1000);
			  Car_Go();
			  delay(1000);
		 }
		 
		 
		 else if(INFRARED_STATE_5()==0)			//¡¡µ∆∑µªÿ0 ”–’œ∞≠ŒÔ¡¡µ∆
		 {
			  Car_Back();
			  delay(1000);
				Car_Stop();
				delay(1000);
				Car_LeftH45();
				delay(1000);
			  Car_Go();
			  delay(1000);
				Car_Left();
		 }
		 
		 
		 else if(INFRARED_STATE_6()==0)			//¡¡µ∆∑µªÿ0 ”–’œ∞≠ŒÔ¡¡µ∆
		 {
			  Car_Go();
				delay(1000);
			  Car_Stop();
			 	delay(1000);
		 	  Car_Turn_Right_Move();
			  delay(1000);
				Car_Back();
			  delay(1000);
		 }
		 
		 
		 else if(INFRARED_STATE_7()==0)			//¡¡µ∆∑µªÿ0 ”–’œ∞≠ŒÔ¡¡µ∆
		 {
				Car_Go();
				delay(1000);
			  Car_Stop();
			 	delay(1000);
		 	  Car_Turn_Right_Move();
			  delay(1000);
				Car_Back();
			  delay(1000);
		 }
		 
		 
		 else if(INFRARED_STATE_8()==0)			//¡¡µ∆∑µªÿ0 ”–’œ∞≠ŒÔ¡¡µ∆
		 {
				Car_Go();
				delay(1000);
			  Car_Stop();
			 	delay(1000);
		 	  Car_Turn_Left_Move();
			  delay(1000);
				Car_Back();
			  delay(1000);
		 }
		 
		 else
		 {
				Car_Go();
		 }
}

