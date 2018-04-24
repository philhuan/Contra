#pragma once
#pragma execution_character_set("utf-8")
#include "PartView.h"

class CannonFodders:public PartView
{
public:
	CannonFodders();
	~CannonFodders();
	View* draw();

private:
	int onCreate();
	RePlayView*toLeft;
	RePlayView*toRight;
	RePlayView*jumpLeft;
	RePlayView*jumpRight;
};

