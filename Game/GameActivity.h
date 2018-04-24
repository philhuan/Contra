#pragma once
#pragma execution_character_set("utf-8")
#include "Activity.h"
#include "Application.h"
#include "Background.h"
#include "Mci.h"
#include "CannonFodders.h"
class GameActivity:public Activity
{
private:   
	double sumFps;
	bool isGameEnd; 
	Mci *backgroundmusic;
public:
	GameActivity();
	double getBackgroundLenght();
	int onCreate();
	bool isExit();
	int ListenKey();
	int moveBackground(int x);
	~GameActivity();
	int trunActivity();

	Background* backGround;
};

extern GameActivity *gameActivity;