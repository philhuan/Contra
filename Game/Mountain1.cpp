#include "Mountain1.h"

Mountain1::Mountain1()
{
	folderToPartView("mountain1", 120, 70);
	setTransparent(true);					//ÉèÖÃÎªÍ¸Ã÷Í¼Æ¬
	onCreate();
}



int Mountain1::onCreate()
{
	page = 0;
	{
		addPosition(240, 70);
		addPosition(400, 70);
	}
	page = 1;
	{
		addPosition(160, 70);
		addPosition(320, 70);
		addPosition(480, 70);
	
	}
	page = 2;
	{
		addPosition(0, 70);
		addPosition(160, 70);
	}
	page = 4;
	{
		addPosition(560, 70);
	}
	return 0;
}


Mountain1::~Mountain1()
{

}