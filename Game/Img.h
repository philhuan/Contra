#pragma once
#pragma execution_character_set("utf-8")

#include <vector>
#include <graphics.h>
#include "Area.h"
class Img
{
protected:
	std::vector<IMAGE> imgs;
	std::vector<long> imgFps;
	long imgFpsSum;
	long getSumto(int i);
	int left;
	int top; 
	int right;
	int bottom;
public:
	Img();
	Img(int left, int top, int right, int bottom);
	long getImgFpsSum();
	IMAGE* getIMAGE(long fps, int i = 0);
	long addImg(IMAGE inImg, long inFpsSum);

};