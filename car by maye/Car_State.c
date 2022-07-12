#include "stm32f10x.h"                  // Device header
#include "Motor.h"


//向前
void Car_Go(void)
{
	//左前电机  前		//右后电机  前
	Motor_A(1);			Motor_B(1);
	
	//左后电机  前		//右后电机  前
	Motor_C(1);			Motor_D(1);
		
}



//向后
void Car_Back(void)
{
	//左前电机  后		//右后电机  后
	Motor_A(2);			Motor_B(2);
	
	//左后电机  后		//右后电机  后
	Motor_C(2);			Motor_D(2);
		
}



//向左
void Car_Left(void)
{
	//左前电机  后		//右后电机  后
	Motor_A(2);			Motor_B(1);
	
	//左后电机  后		//右后电机  后
	Motor_C(1);			Motor_D(2);
		
}



//向左前45
void Car_LeftQ45(void)
{
	//左前电机  后		//右后电机  后
	Motor_A(3);			Motor_B(1);
	
	//左后电机  后		//右后电机  后
	Motor_C(1);			Motor_D(3);
		
}



//向左后45
void Car_LeftH45(void)
{
	//左前电机  后		//右后电机  后
	Motor_A(2);			Motor_B(3);
	
	//左后电机  后		//右后电机  后
	Motor_C(3);			Motor_D(2);
		
}



//向左转圈
void Car_Turn_Left(void)
{
	//左前电机		后	//右前电机		前
	Motor_A(2);			Motor_B(1);
	
	//左后电机		后	//右后电机		前
	Motor_D(2);			Motor_C(1);
}	


//向左平移
void Car_Turn_Left_Move(void)
{
	//左前电机		前	//右前电机		后
	Motor_A(1);			Motor_B(2);
	
	//左后电机		后	//右后电机		前
	Motor_D(2);			Motor_C(1);
}	


//向右
void Car_Right(void)
{
	//左前电机		前	//右前电机		后
	Motor_A(1);			Motor_B(2);
	
	//左后电机		后	//右后电机		前
	Motor_D(2);			Motor_C(1);
}



//向右前度45
void Car_RightQ45(void)
{
	//左前电机		前	//右前电机		停
	Motor_A(1);			Motor_B(3);
	
	//左后电机		停	//右后电机		前
	Motor_D(3);			Motor_C(1);
}



//向右后度45
void Car_RightH45(void)
{
	//左前电机		停	//右前电机		后
	Motor_A(3);			Motor_B(2);
	
	//左后电机		后	//右后电机		停
	Motor_D(2);			Motor_C(3);
}



//向右转圈
void Car_Turn_Right(void)
{
	//左前电机		前	//右前电机		后
	Motor_A(1);			Motor_B(2);
	
	//左后电机		前	//右后电机		后
	Motor_D(1);			Motor_C(2);
}


//向右平移
void Car_Turn_Right_Move(void)
{
	//左前电机		前	//右前电机		后
	Motor_A(2);			Motor_B(1);
	
	//左后电机		后	//右后电机		前
	Motor_D(1);			Motor_C(2);
}	



//停车
void Car_Stop(void)
{
	//左前电机		停	//右前电机		停
	Motor_A(3);			Motor_B(3);

	//左后电机		停	//右后电机		停
	Motor_D(3);			Motor_C(3);
}



