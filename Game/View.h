#pragma once
#pragma execution_character_set("utf-8")
#include "Area.h"

/***
	View是所有可绘制对象的父类
***/
class View:virtual public Area
{
protected:
public:
	int onCreate();
	View();
	View(double x, double y, double width, double height);
	virtual int message(int type, int value);		//用于支持Activity到View的信息传递				
	virtual ~View();
	virtual View* draw();
	virtual bool isExit();
};