#include "StartTitle.h"
#include"HJW.h"

StartTile::StartTile():Area(0,0,640,480)
{
	onCreate();
}

StartTile::~StartTile()
{
}

int StartTile::onCreate()
{
	isLoop = false;
	IMAGE t;
	int titleFps[] = {		//每张图片要显示的次数
		6,2,6,2,
		6,2,6,2,
		6,2,6,2
	};
	for (int i = 0; i < 12; i++)
	{
		char s[20];
		sprintf_s(s, "T%d", i+1);
		SourceToImg(&t, "IMAGE", s, getWidth(), getHeight());
		addIMAGE(t, titleFps[i]);
	}
	return 0;
}
