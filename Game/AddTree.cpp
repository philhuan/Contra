#include "AddTree.h"
#include"main.h"
AddTree::AddTree()
{
}

AddTree::~AddTree()
{
}

int AddTree::setStartPosition(double x, double y)
{
	x += page*srcWidth;
	startPosition.setX(x)->setY(y);
	return 0;
}

int AddTree::add(int list[], int size)
{
	lastWidth = 0;
	for (int i = 0; i < size; i++)
	{
		if ((unsigned)list[i] > partviewList.size())
		{
			debug.GameTip("AddTree list out of range.");
			return 1;
		}
			
		startPosition.setX(startPosition.getX() + lastWidth);
		partviewList[list[i]]->addPosition(startPosition);
		lastWidth = partviewList[list[i]]->getWidth();
		
	}
	return 0;
}

AddTree * AddTree::addPartView(std::vector<PartView*> partviewList)
{
	this->partviewList = partviewList;
	addList();
	return this;
}

void AddTree::addList()
{
	//在这个数组里面添加数据,注意：数据从0开始
	page = 0;
	{
		setStartPosition(80, 155);
		int list[] = { 0,1,2,0,2,0,0,1,1,1,2,0,1,1,2,2,0,1,0,0,1,1,2
		};
		add(list, sizeof(list) / sizeof(int));
	}
	page = 3;
	{
		setStartPosition(320, 155);
		int list[] = { 0,1,1,1,2
		};
		add(list, sizeof(list) / sizeof(int));
	}
	page = 4;
	{
		setStartPosition(400, 155);
		int list[] = { 0,1,1
		};
		add(list, sizeof(list) / sizeof(int));
	}
	page = 5;
	{
		setStartPosition(0, 155);
		int list[] = { 1,1,2
		};
		add(list, sizeof(list) / sizeof(int));
	}
	
}
