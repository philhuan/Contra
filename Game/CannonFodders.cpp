#include "CannonFodders.h"
#include "HJW.h"

CannonFodders::CannonFodders()
{
	onCreate();
}

CannonFodders::~CannonFodders()
{
}

View * CannonFodders::draw()
{
	//jumpRight->draw(100, 100);
	return this;
}

int CannonFodders::onCreate()
{
	IMAGE t;
	SourceToImg(&t, "IMAGE", "PAOHUI", 60*12, 75);
	toLeft = new RePlayView(60, 75, 0xAAAAAA);
	toRight= new RePlayView(60, 75, 0xAAAAAA);
	jumpRight= new RePlayView(60, 75, 0xAAAAAA);
	jumpLeft= new RePlayView(60, 75, 0xAAAAAA);
	IMAGE**imgs = cutIMAGE(&t, 1, 12, 60, 75);
	jumpLeft->addIMAGE(imgs[0][0]);
	for (int i = 5; i > 0; i--)
	{
		toLeft->addIMAGE(imgs[0][i]);
	}
	for (int i = 6; i < 11; i++)
	{
		toRight->addIMAGE(imgs[0][i]);
	}
	jumpRight->addIMAGE(imgs[0][11]);
	return 0;
}
