#pragma once
#pragma execution_character_set("utf-8")
#include"PartView.h"
#include"Physical.h"

enum Bullet_direction {
	BULLET_RIGHT,
	BULLET_LEFT,
	BULLET_UP,
	BULLET_DOWN,
	BULLET_RIGHT_UP,
	BULLET_RIGHT_DOWN,
	BULLET_LEFT_UP,
	BULLET_LEFT_DOWN
};

class Bullet :public Physical
{
public:
	Bullet(double x, double y, Bullet_direction direction);
	~Bullet();
	VecPosition getBulletPosition();
	VecPosition getBulletPositionNoMove();
	bool isShowed;
private:
	int onCreate();
	VecPosition position;
	Bullet_direction bulletDirection;
	static double BULLET_VELOCITY;
	
};

