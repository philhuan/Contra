#pragma once
#pragma execution_character_set("utf-8")
#include "PartView.h"

class Tank:public PartView
{
public:
	Tank();
	~Tank();
	View* draw();
private:
	int onCreate();
	RePlayView **directionFps;
};
