#pragma once
#pragma execution_character_set("utf-8")
#include<vector>
#include"View.h"
#include"KeyListenner.h"


/***
	Activity可以理解为一屏，或者一个界面
***/
class Activity:virtual public KeyListenner
{
	
protected:
	std::vector<View*> viewList;			//View列表
	virtual int onCreate();		//Activity创建时调用，可用来添加View
	
public:
	Activity();
	int addView(View* v);
	virtual ~Activity();
	Activity* run();
	virtual bool isExit();
	virtual int trunActivity();
};

