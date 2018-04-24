#pragma once
#pragma execution_character_set("utf-8")
#include"VecPosition.h"
class Area
{
protected:
	VecPosition position;
	VecPosition size;
public:
	
	Area(double x, double y, double width, double height);
	Area(VecPosition position, VecPosition size);
	Area(VecPosition size);
	Area();
	void setPosition(const VecPosition &position);
	VecPosition getPosition()const;
	void setSize(const VecPosition&size);
	VecPosition getSize()const;
	void setWidth(double width);
	double getWidth()const;
	void setHeight(double height);
	double getHeight()const;
	void setPositionX(double x);
	double getPositionX()const;
	void setPositionY(double y);
	double getPositionY()const;
	bool isInArea(double x, double y)const;//判断一点是不是在区域内
	bool isInArea(const VecPosition &v)const;
	bool isIntersect(const Area &t)const;
	virtual ~Area();
};

