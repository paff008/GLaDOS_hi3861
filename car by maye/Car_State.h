#ifndef __CAR_STATE_H
#define __CAR_STATE_H

//向前
void Car_Go(void);

//向后
void Car_Back(void);

//向左
void Car_Left(void);

//向左前45
void Car_LeftQ45(void);

//向左后45
void Car_LeftH45(void);
	
//向左转圈
void Car_Turn_Left(void);

//向左平移
void Car_Turn_Left_Move(void);

//向右
void Car_Right(void);

//向右前度45
void Car_RightQ45(void);

//向右后度45
void Car_RightH45(void);

//向右转圈
void Car_Turn_Right(void);

//向右平移
void Car_Turn_Right_Move(void);
	
//停车
void Car_Stop(void);

#endif

