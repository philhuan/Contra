#pragma once
#pragma execution_character_set("utf-8")

#include<graphics.h>
#include"PartView.h"
#include"VecPosition.h"
class SimpleImageView:public PartView
{
public:
	SimpleImageView();
	SimpleImageView(double x, double y, double width, double height);
	~SimpleImageView();
	int onCreate();
	int addIMAGE(IMAGE img);
	View* draw();
	View* draw(double x, double y);
	View* draw(VecPosition position);
	View* draw(double x, double y, double width, double height);
private:
	IMAGE image;

};

