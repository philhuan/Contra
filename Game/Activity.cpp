#pragma once
#pragma execution_character_set("utf-8")
#include"Activity.h"


int Activity::onCreate()
{
	return 0;
}

Activity::Activity()
{
	onCreate();
}

int Activity::addView(View * v)
{
	viewList.push_back(v);
	return 0;
}

Activity::~Activity()
{
	for (unsigned int i = 0; i < viewList.size(); i++)
		delete(viewList[i]);
}



Activity* Activity::run()
{
	for (unsigned int i = 0; i <(viewList.size()); i++)
	{
		viewList[i]->draw();
	}
	return this;
}

bool Activity::isExit()
{
	return false;
}

int Activity::trunActivity()
{
	return 0;
}


