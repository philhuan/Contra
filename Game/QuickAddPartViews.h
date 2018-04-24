#pragma once
#pragma execution_character_set("utf-8")

#include<vector>
#include"PartView.h"
#include"VecPosition.h"
#include"Debug.h"
class QuickAddPartViews				//快速添加PartView
{
public:
	QuickAddPartViews();
	~QuickAddPartViews();
	QuickAddPartViews* addPartView(std::vector<PartView*> partviewList);
protected:
	int setStartPosition(double x, double y);
	int add(int list[], int size);
	virtual void addList();
	std::vector<PartView*> partviewList;
	VecPosition startPosition;
	double lastWidth;								//PartView的宽度
	int page;										//支持分页画图
};
