#include "stm32f10x.h"                  // Device header
#include "infrared.h"
void infrared_INIT_1(void)			//C0
{
	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ�����
	
	RCC_APB2PeriphClockCmd(infrared_RCC,ENABLE);	
	GPIO_InitStructure.GPIO_Pin=infrared_PIN_1;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //���ø�������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

}

void infrared_INIT_2(void)			//C1
{
	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ�����
	
	RCC_APB2PeriphClockCmd(infrared_RCC,ENABLE);	
	GPIO_InitStructure.GPIO_Pin=infrared_PIN_2;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //���ø�������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

}

void infrared_INIT_3(void)			//C2
{
	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ�����
	
	RCC_APB2PeriphClockCmd(infrared_RCC,ENABLE);	
	GPIO_InitStructure.GPIO_Pin=infrared_PIN_3;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //���ø�������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

}

void infrared_INIT_4(void)			//C3
{
	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ�����
	
	RCC_APB2PeriphClockCmd(infrared_RCC,ENABLE);	
	GPIO_InitStructure.GPIO_Pin=infrared_PIN_4;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //���ø�������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

}

void infrared_INIT_5(void)			//C4
{
	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ�����
	
	RCC_APB2PeriphClockCmd(infrared_RCC,ENABLE);	
	GPIO_InitStructure.GPIO_Pin=infrared_PIN_5;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //���ø�������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

}

void infrared_INIT_6(void)			//C5
{
	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ�����
	
	RCC_APB2PeriphClockCmd(infrared_RCC,ENABLE);	
	GPIO_InitStructure.GPIO_Pin=infrared_PIN_6;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //���ø�������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

}

void infrared_INIT_7(void)			//C6
{
	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ�����
	
	RCC_APB2PeriphClockCmd(infrared_RCC,ENABLE);	
	GPIO_InitStructure.GPIO_Pin=infrared_PIN_7;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //���ø�������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

}

void infrared_INIT_8(void)			//C7
{
	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ�����
	
	RCC_APB2PeriphClockCmd(infrared_RCC,ENABLE);	
	GPIO_InitStructure.GPIO_Pin=infrared_PIN_8;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //���ø�������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

}




