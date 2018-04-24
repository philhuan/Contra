#include "Area.h"

Area::Area(double x, double y, double width, double height):
	position(x,y),size(width,height)
{
}

Area::Area(VecPosition position, VecPosition size):
	position(position),size(size)
{
}

Area::Area(VecPosition size):position(0,0),size(size)
{
}

Area::Area(): position(),size()
{
}

void Area::setPosition(const VecPosition & position)
{
	this->position = position;
}

VecPosition Area::getPosition() const
{
	return position;
}

void Area::setSize(const VecPosition & size)
{
	this->size = size;
}

VecPosition Area::getSize() const
{
	return size;
}

void Area::setWidth(double width)
{
	size.setX(width);
}

double Area::getWidth() const
{
	return size.getX();
}

void Area::setHeight(double height)
{
	size.setY(height);
}



double Area::getHeight() const
{
	return size.getY();
}

void Area::setPositionX(double x)
{
	position.setX(x);
}

double Area::getPositionX() const
{
	return position.getX();
}

void Area::setPositionY(double y)
{
	position.setY(y);
}

double Area::getPositionY() const
{
	return position.getY();
}

bool Area::isInArea(double x, double y)const
{
	if(x<position.getX()||y<position.getY()) return false;
	if (x > (position + size).getX() || y > (position + size).getY()) return false;
	return true;
}

bool Area::isInArea(const VecPosition & v) const
{
	return isInArea(v.getX(),v.getY());
}

bool Area::isIntersect(const Area & t) const
{
	if (t.getPositionX() + t.getSize().getX() < getPositionX()) return false;
	if (getPositionX() + getSize().getX() < t.getPositionX()) return false;
	if (t.getPositionY() + t.getSize().getY() < getPositionY()) return false;
	if (getPositionY() + getSize().getY() < t.getPositionY()) return false;
	return true;
}




Area::~Area()
{
}
