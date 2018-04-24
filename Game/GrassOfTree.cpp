#include "GrassOfTree.h"
#include"HJW.h"

GrassOfTree::GrassOfTree()
{
	width = 80;
	height = 40;
	drawView = new RePlayView(width, height, 0);
	IMAGE tImg;
	SourceToImg(&tImg, "IMAGE", "GRASS_OF_TREE", 80, 40);
	drawView->addIMAGE(tImg, 8);
	
	onCreate();
}


int GrassOfTree::onCreate()
{
	page = 5;
	{
		drawLine(240, 110,5);
	}
	page = 6;
	{
		drawLine(0, 115,8);
	}
	page = 7;
	{
		drawLine(0, 115,3);
		drawLine(240, 185,5);
	}
	page = 8;
	{
		drawLine(0, 115,5);
		drawLine(400, 255);
		drawLine(480, 185,2);
	}
	page = 9;
	{
		drawLine(80, 250,2);
		drawLine(240, 320,2);
		drawLine(400, 180);
		drawLine(480, 115,2);
	}
	page = 10;
	{
		drawLine(80, 180,2);
		drawLine(240, 250,4);
		drawLine(560, 390);
	}
	page = 11;
	{
		drawLine(80, 320,2);
		drawLine(320, 250,2);
		drawLine(480, 180,4);
	}
	page = 12;
	{
		drawLine(160, 250);
		drawLine(240, 320);
		drawLine(320, 390);
	}
	return 0;
}


GrassOfTree::~GrassOfTree()
{


}
