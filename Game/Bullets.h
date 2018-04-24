#pragma once
#pragma execution_character_set("utf-8")
#include"Bullet.h"


class Bullets :public View
{
public:
	Bullets();
	View*draw();
	View* createBullut(double x, double y, Bullet_direction direction);
	int deletBullut();
	~Bullets();
	bool isAmy;
private:
	int onCreate();
	std::vector<Bullet*> bullets;
	RePlayView *bulletRePlayView;
};