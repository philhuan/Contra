#include "GameActivity.h"
#include"Background.h"
#include"Debug.h"
#include"main.h"
#include"Bill.h"
GameActivity::GameActivity():isGameEnd(false),sumFps(0)
{
	backgroundmusic = new Mci("WAVE", "BACKGROUND_MUSIC");
	backgroundmusic->play();
	debug.GameLog("GameActivity Created!");
	onCreate();
	
}

double GameActivity::getBackgroundLenght()
{
	
	return 0.0;
}

int GameActivity::onCreate()
{
	
	
	addView(backGround=new Background());
	addView(new Bill());
	//addView(new CannonFodders());
	return 0;
}

bool GameActivity::isExit()
{
	return isGameEnd;
}

bool askExit()
{
	int result = MessageBox(GetHWnd(), "Are you sure exit?","Exit?", MB_OK | MB_OKCANCEL);
	if (result == IDOK)
		return true;
	return false;

}

int GameActivity::ListenKey()
{
	sumFps++;
	/*char a[100];
	sprintf_s(a, "%f", gameTime);
	outtextxy(200, 0, a);*/
	if ((long)sumFps % 5800 >= 5799)
	{
		backgroundmusic->stop();
		backgroundmusic->play();
	}
		
	static double lastTime;
	if (lastTime == 0) lastTime = ::gameTime;
	//if (::gameTime - lastTime > 0.1)
	{
		lastTime = ::gameTime;
		{
			if (isClicked(VK_RIGHT))
				viewList[1]->message(Bill::TX, 10);
			if(isClicked(VK_LEFT))
				viewList[1]->message(Bill::TX, -10);
			if(isClicked(VK_UP))
				viewList[1]->message(Bill::TY, -10);
			if (isClicked(VK_DOWN))
				viewList[1]->message(Bill::TY, 10);
			if (isClicked('Z'))
				viewList[1]->message(Bill::M_SHOOT, 1);
			if (isClicked('X'))
				viewList[1]->message(Bill::M_JUMP, 1);
			if (isClicked(VK_ESCAPE))
			{
				if (askExit()) isGameEnd = true;
			}
				

		}

	}
	return 0;
}

int GameActivity::moveBackground(int x)
{
	viewList[0]->message(Background::MOVE, x);
	return 0;
}



GameActivity::~GameActivity()
{

}

int GameActivity::trunActivity()
{
	return 1;
}




