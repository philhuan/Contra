#include "Trunk.h"
#include"HJW.h"

Trunk::Trunk()
{
	folderToPartView("TRUNK", 80, 40);

	onCreate();
}



int Trunk::onCreate()
{
	page = 5;
	{
		drawLine(265, 100,58);
		drawLine(265, 60, 58);
		drawLine(265, 40, 58);
	}
	page = 7;
	{
		drawLine(185, 140,6);
		drawLine(185, 180,6);
		
	}
	page = 8;
	{
		drawLine(345, 140,12);
		drawLine(345, 180,12);
		drawLine(345, 220,2);
		drawLine(345, 260,2);
		drawLine(585, 220,7,1);
	}
	page = 9;
	{
		drawLine(25, 220,7,1);
		drawLine(105, 220, 5);
		drawLine(105, 260,4);
		drawLine(105, 300,4);
		drawLine(185, 340,3);
		drawLine(185, 380,3);
	}
	page = 10;
	{
		drawLine(-55, 140,9,1);
		drawLine(25, 140,9,1);
		drawLine(105, 140,20);
		drawLine(105, 180, 20);
		drawLine(105, 220, 20);
		drawLine(105, 260, 20);
		drawLine(105, 300,20);
		drawLine(105, 340, 20);
		drawLine(105, 380, 20);
		drawLine(105, 420, 20);
		drawLine(105, 460, 14);

	}
	return 0;
}


Trunk::~Trunk()
{
}