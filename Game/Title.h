#pragma once
#pragma execution_character_set("utf-8")

#include"View.h"
#include "RunTitle.h"
#include"StartTitle.h"

enum TitleState {
	START,
	RUN,
	END
};

class Title:public View
{
public:
	Title();
	~Title();
	int message(int type, int value);
	View* draw();
	bool isExit();
private:
	TitleState state;
	bool isReadyEnd;
	bool isEnd;
	RunTitle *runTitle;
	StartTile* startTitle;
	long long sumDrawTimes;

	int onCreate();
	
};
