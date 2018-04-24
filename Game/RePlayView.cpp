#include "main.h"
#include "RePlayView.h"
#include "Debug.h"
#include "HJW.h"

RePlayView::RePlayView() :
	View(0, 0, 100, 100), Area(0, 0, 100, 100)
	, isLoop(true), isSequence(true), isFirstDraw(true), fpsSum(0), firstDrawFps(0), isTransparent(false),
	TransPerantColor(0)
{
	onCreate();
}

RePlayView::RePlayView(double x, double y, double width, double height):
	View( x, y, width, height),Area( x,  y,  width,  height)
	, isLoop(true), isSequence(true), isFirstDraw(true), fpsSum(0), firstDrawFps(0), isTransparent(false),
	TransPerantColor(0)
{
	onCreate();
}

RePlayView::RePlayView(double width, double height):
	View(0, 0, width, height), Area(0, 0, width, height)
	,isLoop(true),isSequence(true),isFirstDraw(true),fpsSum(0),firstDrawFps(0), isTransparent(false),
	TransPerantColor(0)
{
	onCreate();
}

RePlayView::RePlayView(double width, double height,UINT color):
View(0, 0, width, height), Area(0, 0, width, height)
, isLoop(true), isSequence(true), isFirstDraw(true), fpsSum(0), firstDrawFps(0), isTransparent(true),
TransPerantColor(color)
{
	onCreate();
}

int RePlayView::init()
{
	isFirstDraw = true;
	return 0;
}

RePlayView* RePlayView::addIMAGE(IMAGE img, int imgFps)
{
	imgs.push_back(img);
	this->imgFps.push_back(imgFps);
	FpsSumTop.push_back(0);
	for (unsigned int i = 0; i < imgs.size(); i++)
		fpsSum=FpsSumTop[imgs.size() - 1] += this->imgFps[i];
	FpsSumEnd.push_back(0);
	for (unsigned int i = imgs.size() - 1; i >= 0 && i < imgs.size(); i--)
	{
		int a=FpsSumEnd[i] = getSumForEnd(i);
	}
	if (imgs.size() != this->imgFps.size() || imgs.size() != this->imgFps.size())
		debug.GameError("RePlayView	vector操作错误");
	return this;
}

RePlayView * RePlayView::addIMAGE(IMAGE img)
{
	return addIMAGE(img,8);
}

int RePlayView::getFpsSum()
{

	return fpsSum;
}

int RePlayView::update()
{
	int maxi = imgs.size() - 1;
	for (unsigned int i = 0; i < imgs.size(); i++)//更新表
	{
		if (i == 0) FpsSumTop[0] = imgFps[0];
		else
			FpsSumTop[i] = FpsSumTop[i-1] + imgFps[i];
	}

	for (unsigned i = 0; i < imgs.size(); i++)
	{
		if (i == 0) FpsSumEnd[0] = imgFps[maxi];
		else FpsSumEnd[i] = FpsSumEnd[i - 1] + imgFps[maxi - i];
	}
	fpsSum = FpsSumTop[maxi];
	return 0;
}

int RePlayView::onCreate()
{
	return 0;
}

int RePlayView::getSum(int n)
{
	if (n + 1 >(int)( imgFps.size()))
		debug.GameError("RePlayView的getSum参数过大");
	int sum = 0;
	for (int i = 0; i <= n; i++)
		sum += imgFps[i];
	return sum;
}

int RePlayView::getSumForEnd(int n)
{
	int sum = 0;
	for (unsigned int i = n; i < imgFps.size(); i++)
		sum += imgFps[i];
	return sum;
}

View* RePlayView::draw()
{
	return draw(getPositionX(),getPositionY());
}

View * RePlayView::draw(VecPosition *position)
{
	return draw((position->getX()), (position->getY()));
}

View * RePlayView::draw(double x, double y)
{
	return draw(x, y, getWidth(), getHeight());
}

View * RePlayView::draw(double x, double y, double width, double height)
{
	if (isFirstDraw)
	{
		firstDrawFps = sumfps;
		isFirstDraw = false;
	}
	if (fpsSum <= 0)
	{
		debug.GameTip("ReplayView is empty!");
		return this;
	}
	else if (imgs.size() == 1)
	{
		if (isTransparent)
			putbmp(x, y, width, height, &imgs[0], TransPerantColor);
		else
			showImg(x, y, width, height, &imgs[0], 0, 0);
	}
	else
	{
		drawedFps = sumfps - firstDrawFps;
		if (isLoop || drawedFps <= fpsSum)			//判断该不该画不循环的view
		{
			drawTimes++;
			
			int cur = drawedFps % fpsSum;
			if (isSequence)							//如果是顺序播放
			{
				for (unsigned int i = 0; i < imgs.size(); i++)
				{
					if (cur <= FpsSumTop[i])
					{
						if (isTransparent)
							putbmp(x, y, width, height,&imgs[i], TransPerantColor);
						else
							showImg(x, y, width, height, &imgs[i], 0, 0);
						break;
					}
				}
			}
			else									//逆序播放
			{
				static bool notFirst;
				static int cur;
				if (notFirst == false)
				{
					cur = 0;
					notFirst = true;
				}
				cur++;
				for (unsigned int i = imgs.size() - 1; i < imgs.size() && i >= 0; i--)
				{
					int tesytesy = FpsSumEnd[i];
					if (cur <= FpsSumEnd[i])
					{
						showImg(x, y, width, height, &imgs[i], 0, 0);
						break;
					}
				}
			}
		}
		
		
	}
	
	return this;
}

View * RePlayView::draw(const VecPosition & p)
{
	return draw(p.getX(),p.getY());
}

int RePlayView::getImgSum()
{
	return imgs.size();
}

int RePlayView::setFps(unsigned int i, int fps)
{
	if (i >= imgFps.size())
	{
		debug.GameTip("RePlayView setFps i out of range.");
		return 1;
	}
	imgFps[i] = fps;
	update();
	return 0;
}


