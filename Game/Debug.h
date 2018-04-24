#pragma once
#pragma execution_character_set("utf-8")
#include<stdio.h>
class Debug
{
public:
	Debug();
	~Debug();
	 int GameError(char*e);
	 int GameLog(char*l);
	 int GameLog(double num);
	 int GameTip(char*t);
	 int GameTip(double num);
private:
	FILE*lfp;
	FILE*efp;
	HWND dwnd;
};

extern Debug debug;

