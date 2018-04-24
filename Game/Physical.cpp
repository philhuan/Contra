#include "Physical.h"

Physical::Physical()
{
	
}

void Physical::update()
{
	Velocity += Acceleration;
	Position += Velocity;
}

VecPosition Physical::getA() const
{
	return Acceleration;
}

int Physical::setA(const VecPosition & a)
{
	Acceleration = VecPosition(a);
	return 0;
}

VecPosition Physical::getV() const
{
	return Velocity;
}

int Physical::setV(const VecPosition & v)
{
	Velocity = VecPosition(v);
	return 0;
}




