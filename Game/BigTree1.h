#pragma once
#pragma execution_character_set("utf-8")
#include"PartView.h"

class BigTree1 :public PartView
{
public:
	BigTree1();
	~BigTree1();
	View* draw();
	BigTree1*drawLine(double x, double y, int count=1);
private:
	int onCreate();

	
};
