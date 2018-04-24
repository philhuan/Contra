#include "Tank.h"
#include "HJW.h"

Tank::Tank()
{
	size=VecPosition(80, 70);
}

Tank::~Tank()
{
}

View* Tank::draw()
{
	return this;
}

int Tank::onCreate()
{
	double height = size.getY();
	double width = size.getX();
	directionFps = new RePlayView*[12];
	for (int i = 0; i < 12; i++)
		directionFps[i] =new RePlayView(width, height, 0xAAAAAA);
	IMAGE tanks;
	SourceToImg(&tanks, "IMAGE", "WAVE", size.getY() * 5, size.getX() * 4);
	IMAGE**imgs = cutIMAGE(&tanks, 5, 4, 80, 70);
	directionFps[0]->addIMAGE(imgs[0][1], 8);
	for (int i = 0; i < 5; i++)
		directionFps[1 + i]->addIMAGE(imgs[i][2], 8);
	directionFps[6]->addIMAGE(imgs[4][1]);
	//TODO:not wz


	for (int i = 0; i < 5; i++)
	{
		delete [] imgs[i];
	}
	delete[]imgs;
	return 0;
}
