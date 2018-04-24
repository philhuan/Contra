#include "Title.h"
#include"Debug.h"
#include"main.h"
Title::Title():isReadyEnd(false),state(START),sumDrawTimes(0),isEnd(false)
{
	onCreate();
}

Title::~Title()
{
	delete runTitle;
	delete startTitle;
}

int Title::message(int type, int value)
{
	if (type == 1 && value == 1)
	{
		state = END;
		startTitle->init();
		isReadyEnd = true;
	}
		
	return 0;
}

View * Title::draw()
{
	

	if (state == START)
	{
		startTitle->draw();
		sumDrawTimes++;
		if (sumDrawTimes > startTitle->getFpsSum())
		{
			state = RUN;
			draw();
		}
			
	}
	else if (state == RUN)
	{
		runTitle->draw();
	}
	else if(state==END)
	{

		startTitle->isSequence = false;
		startTitle->draw();
	}
	if (isReadyEnd)
	{
		static int leftTimes;
		static bool notfirst;
		if (leftTimes == 0&&notfirst==false)
		{
			notfirst = true;
			
			leftTimes = startTitle->getFpsSum();
		}
		if (leftTimes-- <= 0)
			isEnd = true;
	}

	/*char a[100];
	sprintf_s(a, "%f", gameTime);
	outtextxy(200, 0, a);*/
	return this;
}

bool Title::isExit()
{
	return isEnd;
}

int Title::onCreate()
{
	runTitle = new RunTitle();
	startTitle = new StartTile();
	return 0;
}

