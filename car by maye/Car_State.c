#include "stm32f10x.h"                  // Device header
#include "Motor.h"


//��ǰ
void Car_Go(void)
{
	//��ǰ���  ǰ		//�Һ���  ǰ
	Motor_A(1);			Motor_B(1);
	
	//�����  ǰ		//�Һ���  ǰ
	Motor_C(1);			Motor_D(1);
		
}



//���
void Car_Back(void)
{
	//��ǰ���  ��		//�Һ���  ��
	Motor_A(2);			Motor_B(2);
	
	//�����  ��		//�Һ���  ��
	Motor_C(2);			Motor_D(2);
		
}



//����
void Car_Left(void)
{
	//��ǰ���  ��		//�Һ���  ��
	Motor_A(2);			Motor_B(1);
	
	//�����  ��		//�Һ���  ��
	Motor_C(1);			Motor_D(2);
		
}



//����ǰ45
void Car_LeftQ45(void)
{
	//��ǰ���  ��		//�Һ���  ��
	Motor_A(3);			Motor_B(1);
	
	//�����  ��		//�Һ���  ��
	Motor_C(1);			Motor_D(3);
		
}



//�����45
void Car_LeftH45(void)
{
	//��ǰ���  ��		//�Һ���  ��
	Motor_A(2);			Motor_B(3);
	
	//�����  ��		//�Һ���  ��
	Motor_C(3);			Motor_D(2);
		
}



//����תȦ
void Car_Turn_Left(void)
{
	//��ǰ���		��	//��ǰ���		ǰ
	Motor_A(2);			Motor_B(1);
	
	//�����		��	//�Һ���		ǰ
	Motor_D(2);			Motor_C(1);
}	


//����ƽ��
void Car_Turn_Left_Move(void)
{
	//��ǰ���		ǰ	//��ǰ���		��
	Motor_A(1);			Motor_B(2);
	
	//�����		��	//�Һ���		ǰ
	Motor_D(2);			Motor_C(1);
}	


//����
void Car_Right(void)
{
	//��ǰ���		ǰ	//��ǰ���		��
	Motor_A(1);			Motor_B(2);
	
	//�����		��	//�Һ���		ǰ
	Motor_D(2);			Motor_C(1);
}



//����ǰ��45
void Car_RightQ45(void)
{
	//��ǰ���		ǰ	//��ǰ���		ͣ
	Motor_A(1);			Motor_B(3);
	
	//�����		ͣ	//�Һ���		ǰ
	Motor_D(3);			Motor_C(1);
}



//���Һ��45
void Car_RightH45(void)
{
	//��ǰ���		ͣ	//��ǰ���		��
	Motor_A(3);			Motor_B(2);
	
	//�����		��	//�Һ���		ͣ
	Motor_D(2);			Motor_C(3);
}



//����תȦ
void Car_Turn_Right(void)
{
	//��ǰ���		ǰ	//��ǰ���		��
	Motor_A(1);			Motor_B(2);
	
	//�����		ǰ	//�Һ���		��
	Motor_D(1);			Motor_C(2);
}


//����ƽ��
void Car_Turn_Right_Move(void)
{
	//��ǰ���		ǰ	//��ǰ���		��
	Motor_A(2);			Motor_B(1);
	
	//�����		��	//�Һ���		ǰ
	Motor_D(1);			Motor_C(2);
}	



//ͣ��
void Car_Stop(void)
{
	//��ǰ���		ͣ	//��ǰ���		ͣ
	Motor_A(3);			Motor_B(3);

	//�����		ͣ	//�Һ���		ͣ
	Motor_D(3);			Motor_C(3);
}



