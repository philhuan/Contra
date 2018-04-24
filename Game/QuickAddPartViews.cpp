#include "QuickAddPartViews.h"
#include"main.h"
QuickAddPartViews::QuickAddPartViews()
{
}

QuickAddPartViews::~QuickAddPartViews()
{
}

QuickAddPartViews * QuickAddPartViews::addPartView(std::vector<PartView*> partviewList)
{
	this->partviewList = partviewList;
	addList();
	return this;
}

int QuickAddPartViews::setStartPosition(double x, double y)
{
	x += page*srcWidth;
	startPosition.setX(x)->setY(y);
	return 0;
}

int QuickAddPartViews::add(int list[], int size)
{
	list[1];
	lastWidth = 0;
	for (int i = 0; i < size; i++)
	{
		if ((unsigned)list[i] > partviewList.size()-1)
		{
			debug.GameTip("QuickAddPartViews add() list out of range.");
			return 1;
		}

		startPosition.setX(startPosition.getX() + lastWidth );
		partviewList[list[i]]->addPosition(startPosition);
		lastWidth = partviewList[list[i]]->getWidth();

	}
	return 0;
}

void QuickAddPartViews::addList()
{
	//在这个数组里面添加数据,注意：数据从0开始,add方法可添加数组
	/*setStartPosition(80, 140);
	int list[] = { 0,1,2,0,2,0,0,1,1,1,2,0,1,1,2,2,0,1,0,0,1,1,2
	};
	add(list, sizeof(list) / sizeof(int));*/
}
