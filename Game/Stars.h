#pragma once
#pragma execution_character_set("utf-8")
#include<vector>
#include"VecPosition.h"
#include "PartView.h"
#include "RePlayView.h"

/**
ËùÓÐÐÇÐÇ
*/

class Stars:public PartView
{
public:
	Stars();
	int onCreate();
	~Stars();
	PartView*addStar(int a[], int y, int size);
private:
	VecPosition starSize;
};

