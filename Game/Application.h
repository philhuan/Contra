#pragma once
#pragma execution_character_set("utf-8")
#include "Activity.h"


/***
Application类用来管理各个界面（Activity）。
***/
class Application
{

public:
	int getW();
	int getH();
	Application();
	~Application();
	int start();
	int exit();
	int setActivity(unsigned int i);

protected:
	HWND hwnd;
	std::vector<Activity*> activityList;			//Activity列表
	int thisActivity;						//当前Activity
	bool isGameEnd = false;					//控制游戏结束
	double timeForFps;					//每一帧时间(游戏时间)
	double nowFps;
	double timeDelay;					//每一帧延迟时间（系统时间）
	int testFps();
	int onCreate();

private:
	Activity *startActivity;
	Activity *gameActivity;
};

extern Application *application;