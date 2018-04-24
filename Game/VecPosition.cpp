#include <math.h>
#include<string>
#include "VecPosition.h"


VecPosition::VecPosition():x(0),y(0){}

VecPosition::VecPosition(double x, double y):x(x),y(y){}

VecPosition::VecPosition(const VecPosition & v)
{
	x = v.getX();
	y = v.getY();
}
VecPosition::~VecPosition(){}

double VecPosition::getDistanceTo(const VecPosition &v)const
{
	double dx = fabs(x - v.getX());
	double dy = fabs(y - v.getY());
	return sqrt(dx*dx+dy*dy);
}

double VecPosition::getModulus(const VecPosition & vec) const
{
	return vec.getDistanceTo(VecPosition(0,0));
}

double VecPosition::getModulus() const
{
	return getModulus(*this);
}

double VecPosition::getX()const
{
	return x;
}

double VecPosition::getY()const
{
	return y;
}

VecPosition*  VecPosition::setX(double x)
{
	this->x = x;
	return this;
}

VecPosition*  VecPosition::setY(double y)
{
	this->y = y;
	return this;
}

std::string VecPosition::getS() const
{
	char*p = new char[30];
	sprintf_s(p, 30,"(%.2f,%.2f)", x, y);
	std::string result(p);
	delete[] p;
	return result;
}

VecPosition VecPosition::operator+(const VecPosition &right) const
{
	return VecPosition(x+right.getX(),y+right.getY());
}

VecPosition VecPosition::operator-(const VecPosition &right) const
{
	return VecPosition(x-right.getX(),y-right.getY());
}

VecPosition VecPosition::operator*(const double right) const
{
	return VecPosition(this->x*right, this->y*right);
}

VecPosition VecPosition::operator/(const double right) const
{
	if (right < 0.0000001)
	{
		return VecPosition(0, 0);
	}
	return VecPosition(this->x/right,this->y/right);
}

VecPosition VecPosition::operator+=(const VecPosition & right)
{
	this->setX(this->getX() + right.getX());
	this->setY(this->getY() + right.getY());
	return *this+right;
}

VecPosition VecPosition::operator-=(const VecPosition & right)
{
	this->setX(this->getX() - right.getX());
	this->setY(this->getY() - right.getY());
	return *this - right;
}

VecPosition VecPosition::operator*=(double right)
{
	x *= right;
	y *= right;
	return *this;
}

VecPosition VecPosition::operator/=(double right)
{
	if (right < 0.0000001)
	{
		return *this;
	}
	x /= right;
	y /= right;
	return *this;
}

VecPosition VecPosition::normalization(const VecPosition & vec) const
{
	if (vec.getModulus() < 0.001) return VecPosition(0, 0);
	VecPosition t;
	t = vec*(1 / vec.getModulus());
	return t;
}

VecPosition * VecPosition::normalization()
{
	if (getModulus() < 0.001)
	{
		this->setX(0)->setY(0);
	}
	*this = *this*(1 / getModulus());
	return this;
}





