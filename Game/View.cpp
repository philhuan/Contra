#pragma once
#pragma execution_character_set("utf-8")
#include "View.h"
#include"HJW.h"
int View::onCreate()
{
	return 0;
}

View::View():Area(0,0,0,0)
{
	
	onCreate();
}

View::View(double x, double y, double width, double height)
	:Area(x, y, width, height)
{
	onCreate();
}



int View::message(int type, int value)
{
	return 0;
}




View::~View()
{
	
}

View* View::draw()
{
	
	return this;
}

bool View::isExit()
{
	return false;
}
