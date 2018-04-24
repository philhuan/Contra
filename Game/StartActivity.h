#pragma once
#pragma execution_character_set("utf-8")
#include"Activity.h"


class StartActivity:public Activity
{
private:
public:
	StartActivity();
	int onCreate();
	~StartActivity();
	int ListenKey();
	int trunActivity();
};