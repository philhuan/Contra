#include<cstdlib>
#include<ctime>
#include"Bullets.h"
#include"Area.h"
#include"main.h"
#include"HJW.h"


Bullets::Bullets():isAmy(false)
{
	onCreate();
}

View * Bullets::draw()
{
	
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		VecPosition pos = bullets[i]->getBulletPosition();
		if (bullets[i]->isShowed == false)
			bulletRePlayView->draw(pos);
	}

	deletBullut();
	return this;
}

View * Bullets::createBullut(double x, double y, Bullet_direction direction)
{
	bullets.push_back(new Bullet(x, y, direction));
	return this;
}

int Bullets::deletBullut()
{
	Area src(0, 0, srcWidth, srcHeight);
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		if (src.isInArea(bullets[i]->getBulletPositionNoMove())==false)
		{
			delete bullets[i];
			std::vector<Bullet*>::iterator it = bullets.begin() + i;
			bullets.erase(it);
			i--;
		}
	}
	return 0;
}



Bullets::~Bullets()
{
}

int Bullets::onCreate()
{
	bulletRePlayView = new RePlayView(10, 10, 0xAAAAAA);
	IMAGE t;
	SourceToImg(&t, "IMAGE", "BULLET", 10, 10);
	bulletRePlayView->addIMAGE(t, 8);
	return 0;
}
