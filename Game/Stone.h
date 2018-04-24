#pragma once
#pragma execution_character_set("utf-8")
#include"PartView.h"
#include"RePlayView.h"
class Stone:public PartView
{
public:
	Stone();
	~Stone();
private:
	int onCreate();
	
};

