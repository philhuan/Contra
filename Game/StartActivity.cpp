
#include<string>
#include<sstream>
#include "StartActivity.h"
#include "Debug.h"
#include"Title.h"
#include"main.h"


StartActivity::StartActivity()
{
	debug.GameLog("StartActivity Created!");
	
	onCreate();
}

int StartActivity::onCreate(void)
{
	::PlaySoundA("TITLE_MUSIC", GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	addView(new Title());
	
	return 0;
}

StartActivity::~StartActivity()
{
	debug.GameLog("StartActivity deleted!");
}

int StartActivity::ListenKey()
{

	static bool isChecked;
	if (isChecked == false)
	{
		
		if (isClicked(VK_RETURN)&&gameTime>3)				//»Ø³µ¼ü
			{
				isChecked = true;
				viewList[0]->message(1, 1);
			}
	}
	
	return 0;
}

int StartActivity::trunActivity()
{
	if (viewList[0]->isExit())
		return 1;
	return 0;
}






