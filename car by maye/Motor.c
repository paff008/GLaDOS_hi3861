#include "stm32f10x.h"  // Device header
#include "PWM.h"
//配置四个电机的IO口lo

//左前 	PA12	PA13
void Motor_Init_Motor1(void)								
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能PB端口时钟
  
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13;//端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
  GPIO_Init(GPIOB, &GPIO_InitStructure);		//根据设定参数初始化GPIOB 
  //暂时先把IO口拉低电平，也可以不拉
  GPIO_ResetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13);
	PWM_Init();
}

//右后 	PA7	PA8
void Motor_Init_Motor2(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能PB端口时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8;//端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
  GPIO_Init(GPIOB, &GPIO_InitStructure);		//根据设定参数初始化GPIOB 
  //暂时先把IO口拉低电平，也可以不拉
  GPIO_ResetBits(GPIOB,GPIO_Pin_7|GPIO_Pin_8);
}

//左后 	PA5	PA6
void Motor_Init_Motor3(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能PB端口时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6;//端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
  GPIO_Init(GPIOB, &GPIO_InitStructure);		//根据设定参数初始化GPIOB 
  //暂时先把IO口拉低电平，也可以不拉
  GPIO_ResetBits(GPIOB,GPIO_Pin_5|GPIO_Pin_6);
}
		
//右前 	PA14	PA15
void Motor_Init_Motor4(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能PB端口时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_15;//端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
  GPIO_Init(GPIOB, &GPIO_InitStructure);		//根据设定参数初始化GPIOB 
  //暂时先把IO口拉低电平，也可以不拉
  GPIO_ResetBits(GPIOB,GPIO_Pin_14|GPIO_Pin_15);
}




//****************************************

//左前电机
void Motor_A(int state)
{
	if(state == 1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		PWM_SetCompare1(60);
	}
	
	if(state==2)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_13);
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		PWM_SetCompare1(60);
	}
	
	if(state==3)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		PWM_SetCompare1(60);
	}
	
}

//右后电机
void Motor_D(int state)                     //1代表GO 2代表BACK 3代表STOP
{
	
	if(state==1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_7);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
		PWM_SetCompare4(60);
	}
	
	
	if(state==2)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_8);
		GPIO_ResetBits(GPIOB,GPIO_Pin_7);
		PWM_SetCompare4(60);
	}
	
	
	if(state==3)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_7);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	}
	
}

//左后电机
void Motor_C(int state)                     //1代表GO 2代表BACK 3代表STOP
{
	
	if(state==1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		PWM_SetCompare3(60);
	}
	
	
	if(state==2)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_6);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		PWM_SetCompare3(60);
	}
	
	
	if(state==3)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	}
	
}


//右前电机
void Motor_B(int state)                     //1代表GO 2代表BACK 3代表STOP
{
	
	if(state==1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
		GPIO_ResetBits(GPIOB,GPIO_Pin_15);
		PWM_SetCompare2(60);
	}
	
	
	if(state==2)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_15);
		GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		PWM_SetCompare2(60);
	}
	
	
	if(state==3)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		GPIO_ResetBits(GPIOB,GPIO_Pin_15);
	}
	
}

/************************************************************************/


/*void Motor_SetSpeed_A()			//左前
{
	
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		PWM_SetCompare1(60);
	
}



void Motor_SetSpeed_B()			//右前
{
	
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
		GPIO_ResetBits(GPIOB,GPIO_Pin_15);
		PWM_SetCompare2(60);
	
}


void Motor_SetSpeed_D()			//右后
{
	
		GPIO_SetBits(GPIOB,GPIO_Pin_7);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
		PWM_SetCompare4(60);
	
}

void Motor_SetSpeed_C()			//左后
{
	
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		PWM_SetCompare3(60);
	
}

void Motor_AA()
{
	
}*/
