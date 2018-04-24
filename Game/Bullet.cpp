#include "Bullet.h"


double Bullet::BULLET_VELOCITY = 5;
Bullet::Bullet(double x, double y, Bullet_direction direction) :
	position(VecPosition(x, y)), bulletDirection(direction), isShowed(true)
{
	onCreate();
}



Bullet::~Bullet()
{
}



VecPosition Bullet::getBulletPosition()
{
	static long drawTime;
	if (drawTime++%16 > 7)
		isShowed = true;
	else
		isShowed = false;
	position += Velocity;
	return position;
}

VecPosition Bullet::getBulletPositionNoMove()
{
	return position;
}



int Bullet::onCreate()
{
	::PlaySoundA("GUN_MUSIC", GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	double velocity[8][3] = {
		{1.0,0},//RIGHT
		{-1.0,0},//LEFT
		{0,-1.0},//UP
		{0,1.0},//DOWN
		{1.0,-1.0},//RIGHT_UP
		{1.0,1.0},//RIGHT_DOWN
		{-1.0,-1.0},//LEFT_UP
		{-1.0,1.0 }//LEFT_DOWN
	};
	Bullet_direction direc[8] = {
		BULLET_RIGHT,
		BULLET_LEFT,
		BULLET_UP,
		BULLET_DOWN,
		BULLET_RIGHT_UP,
		BULLET_RIGHT_DOWN,
		BULLET_LEFT_UP,
		BULLET_LEFT_DOWN
	};
	int i = -1;
	while (bulletDirection != direc[++i]);
	Velocity = VecPosition(velocity[i][0], velocity[i][1]);
	Velocity.normalization();
	Velocity *= BULLET_VELOCITY;
	return 0;
}

