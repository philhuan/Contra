#include "PartView.h"
#include"main.h"
#include"Debug.h"
#include"HJW.h"
PartView::PartView():Area(0,0,100,100), mapLength(0), isBinded(false),drawView(NULL), folder("image\\stage\\"),page(0)
{
	onCreate();
}

PartView::PartView(double width, double height, LPCTSTR pImgFile): Area(0, 0, width, height), mapLength(0),  page(0),
isBinded(false), drawView(NULL), folder("image\\stage\\")
{
	folderToPartView(pImgFile, width, height);
	onCreate();
}

PartView::PartView(double width, double height, RePlayView * inView)
	: Area(0, 0, width, height), mapLength(0), page(0),
	isBinded(false), drawView(NULL), folder("image\\stage\\")
{
	drawView = inView;
	onCreate();
}

PartView::PartView(double x, double y, double width, double height)
	:View(x,y,width,height),Area(x, y, width, height), mapLength(0), isBinded(false), folder("image\\stage\\"), page(0)
{
	onCreate();
}

int PartView::onCreate()
{
	return 0;
}

int PartView::bindCurPosition(const VecPosition * curPosition)
{
	isBinded = true;
	this->curPosition = curPosition;
	return 0;
}



VecPosition PartView::g2l(const VecPosition & g)const
{
	return (g-*curPosition);
}



int PartView::setTransparent(bool isTransparent)
{
	drawView->isTransparent = isTransparent;
	drawView->isTransparent = true;
	return 0;
}

bool PartView::isWillShow(const VecPosition & position, const VecPosition & size)const
{
	if (isBinded == false)
		debug.GameTip("PartView is never binded.");
	VecPosition local = g2l(position);		//转换为窗口坐标
	if ((local + size).getX() < 0 || local.getX() > srcWidth)
		return false;
	if ((local + size).getY() < 0 || local.getY() > srcHeight)
		return false;
	return true;
}

void PartView::folderToPartView(LPCTSTR pResName,
	double viewSizeX, double viewSizeY, int fps)
{
	width = viewSizeX;
	height = viewSizeY;
	drawView = new RePlayView(viewSizeX, viewSizeY);
	IMAGE tIMG;
	SourceToImg(&tIMG, "IMAGE", pResName, drawView->getWidth(), drawView->getHeight());
	drawView->addIMAGE(tIMG, 8);
}




double PartView::getMapMax() const
{
	double max = 0;
	for (unsigned int i = 0; i < vecList.size(); i++)
	{
		if (vecList[i].getX()+drawView->getWidth() > max) max = vecList[i].getX() + drawView->getWidth();
	}
	return max;
}


PartView* PartView::addPosition(const VecPosition & position)
{
	vecList.push_back(position+VecPosition(page*srcWidth,0));
	return this;
}

PartView* PartView::addPosition(double x, double y)
{
	x += page*srcWidth;
	vecList.push_back(VecPosition(x,y));
	return this;
}


PartView* PartView::addPosition(const int array[][2],int size)
{
	if (array == 0)
		return addPosition(0.0, size);			//防止将0误认为指针NULL
	for (int i = 0; i < size; i++)
	{
		VecPosition p(array[i][0], array[i][1]);
		addPosition(p);
	}
	return this;
}

PartView* PartView::drawLine(double x, double y, int count, int direction)
{
	if (direction == 0)
	{
		for (int i = 0; i < count; i++)
			addPosition(x + i*width, y );
	}
	else
	{
		for (int j = 0; j < count; j++)
			addPosition(x, y+j*height);
	}
	return this;
}

unsigned int PartView::getViewcount() const
{
	return vecList.size();
}

View * PartView::draw()
{
	for (unsigned int i = 0; i < vecList.size(); i++)
	{
		if (isWillShow(vecList[i], drawView->getSize()))
		{
			drawView->draw(&g2l(vecList[i]));
		}

	}
	return this;
}

PartView* PartView::setVecList(const std::vector<VecPosition> & list)
{
	vecList = list;
	return this;
}

std::vector<VecPosition> PartView::getVecList()
{
	return vecList;
}





PartView::~PartView()
{
	if (drawView != NULL)
		delete drawView;
}

int PartView::setPage(int page)
{
	this->page = page;
	return 0;
}
