#pragma once
#pragma execution_character_set("utf-8")
#include"Img.h"

Img::Img():left(0),top(0),right(100),bottom(100)
{
	imgFpsSum = 0;
}

Img::Img(int left, int top, int right, int bottom):
	left(left),top(top),right(right),bottom(bottom)
{
	imgFpsSum = 0;
}

long Img::getSumto(int i)
{
	long sum = 0;
	for (int j = 0; j <= i; j++)
	{
		sum += imgFps[i];

	}
	return sum;
}



long Img::getImgFpsSum()
{
	return imgFpsSum;
}
IMAGE * Img::getIMAGE(long fps, int i)
{
	if (getSumto(i) <= fps)
		return getIMAGE(fps, ++i);
	return &imgs[i];
}
/***
inImg为传入的IMAGE对象，inFpsSum为此图片显示帧数
***/
long Img::addImg(IMAGE inImg, long inFpsSum)
{
	imgs.push_back(inImg);
	imgFps.push_back(inFpsSum);
	imgFpsSum += inFpsSum;
	return 0;
}
