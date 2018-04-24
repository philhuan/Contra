#include "Stone.h"
#include"HJW.h"
Stone::Stone()
{
	folderToPartView("stone", 160, 70);
	onCreate();
}


int Stone::onCreate()
{
	page = 0;
	{
	drawLine(80, 260, 4);
	drawLine(80, 330, 4);
	drawLine(400, 290);
	drawLine(480, 290);
	drawLine(400, 360,2);
	}
	page = 1;
	{
		drawLine(80, 260,3);
		drawLine(80, 330,2);
		drawLine(480, 260);
		drawLine(480, 330);
		drawLine(80, 360);
		drawLine(160,360);
		drawLine(400, 300);
		drawLine(400, 370);
		
	}
	page = 2;
	{
		drawLine(0, 260,4);
		drawLine(0, 330, 4);
		drawLine(160, 360,2);
		drawLine(400, 360);
	}
	page = 3;
	{
		drawLine(320, 260, 2);
		drawLine(320, 330,2);
		drawLine(560, 260)->drawLine(560, 330);

	}
	page = 4;
	{
		drawLine(400, 330,2);
		drawLine(400, 260, 2);
		drawLine(560, 360);
	}
	page = 5;
	{
		drawLine(80, 260, 4);
		drawLine(80, 330, 4);
		drawLine(80, 360,4);
		drawLine(240, 190,3);
	}
	page = 6;
	{
		drawLine(80, 260, 4);
		drawLine(80, 330,4);
		drawLine(600, 400);
		drawLine(600, 470);
		drawLine(160, 360, 3);
		drawLine(80, 190, 4);
		
	}
	page = 7;
	{
		drawLine(80, 190);
		drawLine(80, 260,4);
		drawLine(80, 330,4);
		drawLine(80, 400,4);
		drawLine(80, 470,4);
	}
	page = 8;
	{
		drawLine(0, 190,2);
		drawLine(240, 190);
		drawLine(80, 260,2);
		drawLine(480, 260);
		drawLine(80, 330,3);
		drawLine(480, 330);
		drawLine(80, 400, 2);
		drawLine(320, 400,2);
		drawLine(80, 470,2);
		drawLine(320, 470, 2);
	}
	page = 9;
	{
		drawLine(480, 190,5,1);
		drawLine(400, 260);
		drawLine(80, 330);
		drawLine(400, 330);
		drawLine(80, 400,3);
		drawLine(80, 470,3);
	}
	page = 10;
	{
		drawLine(80, 260);
		drawLine(80, 330,3);
		drawLine(80, 400,3);
		drawLine(80, 470,3);
		drawLine(480, 470);
	}
	page = 11;
	{
		drawLine(80, 400);
		drawLine(80, 470);
		drawLine(320, 330,3);
		drawLine(320, 400,4);
		drawLine(320, 470, 5);
		drawLine(480, 260,2);
	}
	page = 12;
	{
		drawLine(80, 330);
	}
	return 0;
}




Stone::~Stone()
{
}
