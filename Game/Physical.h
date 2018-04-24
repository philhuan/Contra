#pragma once
#pragma execution_character_set("utf-8")
#include "VecPosition.h"
class Physical
{
protected:
	VecPosition Position;		//位置
	VecPosition Velocity;		//速度
	VecPosition Acceleration;	//加速度
public:
	Physical();
	void update();
	VecPosition getA()const;
	int setA(const VecPosition &a);
	VecPosition getV()const;
	int setV(const VecPosition &v);
};
