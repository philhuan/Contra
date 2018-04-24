#pragma once
#pragma execution_character_set("utf-8")
#include"Img.h"

class ReverseAbleImg:public Img
{
public:
	ReverseAbleImg();
	~ReverseAbleImg();
	IMAGE* getInIMAGE(long fps, int i = 0);
	IMAGE* getOutIMAGE(long fps);
private:

};

