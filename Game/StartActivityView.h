#pragma once
#pragma execution_character_set("utf-8")
#include"View.h"
#include<vector>
#include"Img.h"
#include "ReverseAbleImg.h"


class StartActivittyView :public View
{

	Img runImgs;
	ReverseAbleImg gradientImgs;
	long endFps;
	long createFpsSum;
public:
	int getGradientLength();
	View* draw();
	int onCreate();
	StartActivittyView();
	~StartActivittyView();
};