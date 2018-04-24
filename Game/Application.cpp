#pragma once
#pragma execution_character_set("utf-8")
#include<Windows.h>
#include"main.h"
#include"Application.h"
#include "StartActivity.h"
#include"GameActivity.h"
#include"Debug.h"


int srcWidth;			//屏幕宽度
int srcHeight;			//屏幕高度
int fps;				//游戏额定fps
double gameTime;			//游戏运行总时间（非系统时间）
long long sumfps;		//游戏刷新总帧数
GameActivity *gameActivity;

Application::Application()
{
	debug.GameLog("Application Created!");
	fps = 60;
	gameTime = 0;
	timeForFps = 1.0 / (fps+1);
	srcHeight = 480;
	srcWidth = 640;
	sumfps = 0;
	
	initgraph(srcWidth,srcHeight);		//初始化窗口
	hwnd = GetHWnd();					//获取窗口句柄
	SetWindowTextW(hwnd,L"魂斗罗");
	onCreate();
	
}

Application::~Application()
{
	for (int i = 0; activityList.size(); i++)
		delete(activityList[i]);
	closegraph(); 
}

int Application::onCreate()
{
	
	activityList.push_back(startActivity);
	activityList.push_back(gameActivity);
	thisActivity = 0;
	setActivity(thisActivity);
	return 0;
}

int Application::getW()
{
	return srcWidth;
}

int Application::getH()
{
	return srcHeight;
}

int Application::testFps()
{
	static DWORD last;
	if(last==0)last= timeGetTime();
	static int times;		//次数
	if (times++ >= 60)
	{
		nowFps = 1000.0/(timeGetTime() - last)*60;
		times = 0;
		//debug.GameLog(nowFps);
		last = timeGetTime();
	}
	return 0;
}


int Application::start()
{
	char s[20];
	debug.GameLog("Application start.");
	LARGE_INTEGER frequency,				//机器支持的高精度计时器频率
		last, cur;
	if (QueryPerformanceFrequency(&frequency) == false)
	{
		debug.GameError("不支持高精度计时器。");
		return 1;
	}
	while (isGameEnd==false)
	{
		QueryPerformanceCounter(&last);
		testFps();
		BeginBatchDraw();		//绘图缓冲
		cleardevice();
		activityList[thisActivity]->ListenKey();
		activityList[thisActivity]->run();
		sprintf_s(s, "fps:%.2f", nowFps);
		outtextxy(0, 0, s);
		//FlushBatchDraw();
		EndBatchDraw();
		sumfps++;
		gameTime += timeForFps;
		isGameEnd = activityList[thisActivity]->isExit();
		if (activityList[thisActivity]->trunActivity() != thisActivity)
			setActivity(activityList[thisActivity]->trunActivity());
		for (QueryPerformanceCounter(&cur);
			(cur.QuadPart - last.QuadPart) / (double)(frequency.QuadPart) < timeForFps /*|| GetForegroundWindow() != hwnd*/
			;)
		{
			QueryPerformanceCounter(&cur);
		}
	}
	debug.GameLog("Applicationt退出start.");
	return 0;
	
}

int Application::exit()
{
	isGameEnd = true;
	debug.GameLog("Application Exit");
	return 0;
}

int Application::setActivity(unsigned int i)
{
	char s[40];
	sprintf_s(s, 40,"Application setApplication (%u)",i);
	debug.GameLog(s);
	
	
	if (activityList[thisActivity] != NULL)
	{
		delete activityList[thisActivity];
		activityList[thisActivity] = NULL;
		thisActivity = i;
		setActivity(i);
	}
	else
	{
		if (i == 0)
			activityList[thisActivity] = new StartActivity();
		else if (i == 1)
			activityList[thisActivity] =::gameActivity = new GameActivity();
		else
			debug.GameTip(i);
	}
	
	return 0;
}
