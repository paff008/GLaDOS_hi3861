#include "stm32f10x.h"  // Device header
#include "PWM.h"
//�����ĸ������IO��lo

//��ǰ 	PA12	PA13
void Motor_Init_Motor1(void)								
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //ʹ��PB�˿�ʱ��
  
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13;//�˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
  GPIO_Init(GPIOB, &GPIO_InitStructure);		//�����趨������ʼ��GPIOB 
  //��ʱ�Ȱ�IO�����͵�ƽ��Ҳ���Բ���
  GPIO_ResetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13);
	PWM_Init();
}

//�Һ� 	PA7	PA8
void Motor_Init_Motor2(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //ʹ��PB�˿�ʱ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8;//�˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
  GPIO_Init(GPIOB, &GPIO_InitStructure);		//�����趨������ʼ��GPIOB 
  //��ʱ�Ȱ�IO�����͵�ƽ��Ҳ���Բ���
  GPIO_ResetBits(GPIOB,GPIO_Pin_7|GPIO_Pin_8);
}

//��� 	PA5	PA6
void Motor_Init_Motor3(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //ʹ��PB�˿�ʱ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6;//�˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
  GPIO_Init(GPIOB, &GPIO_InitStructure);		//�����趨������ʼ��GPIOB 
  //��ʱ�Ȱ�IO�����͵�ƽ��Ҳ���Բ���
  GPIO_ResetBits(GPIOB,GPIO_Pin_5|GPIO_Pin_6);
}
		
//��ǰ 	PA14	PA15
void Motor_Init_Motor4(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //ʹ��PB�˿�ʱ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_15;//�˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
  GPIO_Init(GPIOB, &GPIO_InitStructure);		//�����趨������ʼ��GPIOB 
  //��ʱ�Ȱ�IO�����͵�ƽ��Ҳ���Բ���
  GPIO_ResetBits(GPIOB,GPIO_Pin_14|GPIO_Pin_15);
}




//****************************************

//��ǰ���
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

//�Һ���
void Motor_D(int state)                     //1����GO 2����BACK 3����STOP
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

//�����
void Motor_C(int state)                     //1����GO 2����BACK 3����STOP
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


//��ǰ���
void Motor_B(int state)                     //1����GO 2����BACK 3����STOP
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


/*void Motor_SetSpeed_A()			//��ǰ
{
	
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		PWM_SetCompare1(60);
	
}



void Motor_SetSpeed_B()			//��ǰ
{
	
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
		GPIO_ResetBits(GPIOB,GPIO_Pin_15);
		PWM_SetCompare2(60);
	
}


void Motor_SetSpeed_D()			//�Һ�
{
	
		GPIO_SetBits(GPIOB,GPIO_Pin_7);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
		PWM_SetCompare4(60);
	
}

void Motor_SetSpeed_C()			//���
{
	
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		PWM_SetCompare3(60);
	
}

void Motor_AA()
{
	
}*/
