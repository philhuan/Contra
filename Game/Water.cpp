#include "Water.h"
#include"HJW.h"
Water::Water()
{
	folderToPartView("water", 80, 80);
	onCreate();
}

int Water::onCreate()
{
	page = 0;
	{
		for (int i = 0; i < 2; i++)
		{
			addPosition(0, 400 - i*height);
		}
		drawLine(80, 400, 24);
	}
	
	page = 3;
	{
		drawLine(0, 290, 4);
		drawLine(0, 360, 4);
		drawLine(0, 400, 8);
	}
	page = 4;
	{
		drawLine(0, 400,8);
		drawLine(80, 290,4);
		drawLine(80, 330, 4);
	}
	page = 5;
	{
		drawLine(0, 430,8);
	}
	page = 6;
	{
		drawLine(0, 430,7);
		addPosition(80, 395);
		addPosition(520, 430);
	}
	return 0;
}

Water::~Water()
{
}


