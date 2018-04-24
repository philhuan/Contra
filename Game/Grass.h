#pragma once
#pragma execution_character_set("utf-8")
#include"PartView.h"

class Grass:public PartView
{
public:
	Grass();
	~Grass();

private:
	double offsetWithStone;

	int onCreate();
	int drawOnStone(double x, double y, int count=1,double offsetWithStone =1);
};

