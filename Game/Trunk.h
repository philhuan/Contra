#pragma once
#pragma execution_character_set("utf-8")
#include"PartView.h"
class Trunk:public PartView
{
public:
	Trunk();
	~Trunk();

private:
	int onCreate();
};


