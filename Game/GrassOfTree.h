#pragma once
#pragma execution_character_set("utf-8")
#include"PartView.h"

class GrassOfTree:public PartView
{
public:
	GrassOfTree();
	~GrassOfTree();

private:
	int onCreate();
};

