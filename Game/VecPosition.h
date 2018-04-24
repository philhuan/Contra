#pragma once
#pragma execution_character_set("utf-8")
#include <string>

class VecPosition
{
public:
	VecPosition();
	VecPosition(double x, double y);
	VecPosition(const VecPosition &v);
	~VecPosition();
	double getDistanceTo(const VecPosition &v)const;
	double getModulus(const VecPosition &vec)const;
	double getModulus()const;
	double getX()const;
	double getY()const;
	VecPosition* setX(double x);
	VecPosition* setY(double y);
	std::string getS()const;
	VecPosition operator +(const VecPosition &right)const;
	VecPosition operator -(const VecPosition &right)const;
	VecPosition operator *(const double right)const;
	VecPosition operator/(const double right)const;
	VecPosition operator+=(const VecPosition &right);
	VecPosition operator-=(const VecPosition &right);
	VecPosition operator*=(double right);
	VecPosition operator/=(double right);
	VecPosition normalization(const VecPosition &vec)const;
	VecPosition* normalization();
protected:
	double x, y;


};



