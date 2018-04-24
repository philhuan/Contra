#include "BigTree1.h"
#include"HJW.h"
#include<cstdlib>
#include<ctime>

BigTree1::BigTree1()
{
	drawView = new RePlayView(110,70,0);
	IMAGE timg;
	SourceToImg(&timg, "IMAGE","BIGTREE", 110, 280);
	IMAGE**Ibigtree= cutIMAGE(&timg, 4, 1, 110, 70);
	for (int i = 0; i < 4; i++)
	{
		drawView->addIMAGE(Ibigtree[i][0], 8);
	}
	


	onCreate();
}

BigTree1::~BigTree1()
{
}

View * BigTree1::draw()
{
	//实现fps随机变化
	static int count;
	if (count++ >= drawView->getFpsSum())
	{
		srand((unsigned)time(NULL));
		for (int i = 0; i < drawView->getImgSum(); i++)
		{
			int thisTimeFps = 5 + rand() % 8;
			drawView->setFps(i, thisTimeFps);
		}
		count = 0;
	}
	return PartView::draw();
	return this;
}

BigTree1 * BigTree1::drawLine(double x, double y, int count)
{
	int width = 75;
	for (int i = 0; i < count; i++)
	{
		addPosition(x + i*width, y);
	}
	return this;
}

int BigTree1::onCreate()
{
	page = 5;
	{
		drawLine(255, 15,60);
	}
	page = 10;
	{
		drawLine(150, 70,20);
	}
	return 0;
}
