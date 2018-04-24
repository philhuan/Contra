#include "Title.h"
#include"HJW.h"

RunTitle::RunTitle():Area(0, 0, 640, 480)
{
	onCreate();
}

RunTitle::~RunTitle()
{

}

int RunTitle::onCreate()
{
	IMAGE t;
	int titleFps[] = {		//每张图片要显示的次数
		6,8,8,8
	};
	for (int i = 0; i < 4; i++)
	{
		char s[20];
		sprintf_s(s, "T%d", i+13);
		SourceToImg(&t, "IMAGE", s,getWidth(),getHeight());
		addIMAGE(t, titleFps[i]);
	}
	
	return 0;
}

