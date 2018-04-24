#include "Mountain2.h"

Mountain2::Mountain2()
{
	folderToPartView("mountain2", 90, 100);
	setTransparent(true);					//ÉèÖÃÎªÍ¸Ã÷Í¼Æ¬
	onCreate();
}



int Mountain2::onCreate()
{
	page = 0;
	{
		addPosition(340, 55);
		addPosition(500, 55);
	}
	page = 1;
	{
		addPosition(260, 55);
		addPosition(420, 55);
		addPosition(580, 55);
	}
	page = 2;
	{
		addPosition(100, 55);
		addPosition(260, 55);
	}
	page = 5;
	{
		addPosition(20, 55);
	}
	return 0;
}


Mountain2::~Mountain2()
{
}