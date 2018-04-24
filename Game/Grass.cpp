#include "Grass.h"

Grass::Grass()
{
	
	folderToPartView("grass", 80, 40);
	offsetWithStone =- height;
	onCreate();
}

Grass::~Grass()
{
}

int Grass::onCreate()
{
	
	page = 0;
	{
		drawOnStone(80, 220, 16, 0);
		drawOnStone(400, 290, 3, 0);
		drawOnStone(640, 360, 1, 0);
	}
	page = 1;
	{
		drawLine(80, 430,2);
		drawLine(240, 360);
		drawLine(400, 300,2);
	}
	page = 2;
	{
		drawLine(80, 220,7);
		drawLine(240, 430,2);
		drawLine(320, 330,3);
		
	}
	page = 3;
	{
		drawLine(320, 220,5);
	}
	page = 4;
	{
		drawLine(400, 220,3);
	}
	page = 5;
	{
		drawLine(0, 220,5);
		drawLine(240, 150,5);
		drawLine(320, 430,3);
		drawLine(560, 320);
	}
	page = 6;
	{
		drawLine(0, 320);
		drawLine(0, 150,8);
		drawLine(160, 290,6);
		drawLine(480, 430,2);
	}
	page = 7;
	{
		drawLine(0, 155,3);
		drawLine(160, 225,6);
		drawLine(0, 290);
		drawLine(320, 360,2);
		drawLine(560, 360);
		drawLine(0, 430,4);
	}
	page = 8;
	{
		drawLine(0, 155,5);
		drawLine(0, 225);
		drawLine(0, 360);
		drawLine(160, 330);
		drawLine(320, 290,3);
		drawLine(480, 225,2);
	}
	page = 9;
	{
		drawLine(80, 290,2);
		drawLine(160, 360,3);
		drawLine(80, 430);
		drawLine(400, 220,2);
		drawLine(480, 155,2);
		drawLine(560, 330);
		drawLine(480, 430);
	}
	page = 10;
	{
		drawLine(80, 220,2);
		drawLine(160, 290,5);
		drawLine(400, 430,3);
	}
	page = 11;
	{
		drawLine(80, 360,2);
		drawLine(320, 290,2);
		drawLine(480, 220,4);
		drawLine(560, 330,3);
		drawLine(480, 430,8);
	}
	page = 12;
	{
		drawLine(160, 290);
		drawLine(240, 360);
	}
	
	
	return 0;
}



int Grass::drawOnStone(double x, double y, int count,double offsetWithStone)
{
	if (offsetWithStone == 1) offsetWithStone = this->offsetWithStone;
	if (offsetWithStone == -1) offsetWithStone = -this->offsetWithStone;
	for (int i = 0; i < count; i++)
	{
		addPosition(x + width*i, y + offsetWithStone);
	}
	return 0;
}
