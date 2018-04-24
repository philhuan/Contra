#include "ReverseAbleImg.h"

ReverseAbleImg::ReverseAbleImg()
{
}

ReverseAbleImg::~ReverseAbleImg()
{
}

IMAGE * ReverseAbleImg::getInIMAGE(long fps, int i)
{
	if (getSumto(i) <= fps)
		return getInIMAGE(fps, ++i);
	return &imgs[i];
}

IMAGE * ReverseAbleImg::getOutIMAGE(long fps)
{
	for (unsigned int i = imgs.size()-1; i >= 0&&i<imgs.size(); i--)
	{
		if (fps >getSumto(i))
		{
			
			return &imgs[i];
		}
		
	}
	return &imgs[0];
}
