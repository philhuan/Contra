#pragma once
#pragma execution_character_set("utf-8")

#include<vector>
#include"RePlayView.h"
#include"VecPosition.h"
/*
继承partView后，使用PartView自带的PartView指针drawView载入图片，drawView不用delete
*/
class PartView:public View
{
public:
	
	PartView();
	PartView(double width,double height, LPCTSTR pImgFile);
	PartView(double width, double height, RePlayView*inView);
	PartView(double x, double y, double width, double height);
	unsigned int getViewcount()const;
	virtual View* draw();
	PartView* addPosition(const VecPosition &position);
	PartView* addPosition(double x, double y);
	PartView* addPosition(const int array[][2], int size);
	PartView* drawLine(double x, double y, int count = 1,int direction = 0);
	PartView* setVecList(const std::vector<VecPosition> & list);
	std::vector<VecPosition> getVecList();
	double getMapMax()const;												//获取View的最大坐标
	int bindCurPosition(const VecPosition *curPosition);					//设置镜头在地图的位置
	~PartView();
	int setPage(int page);
	double page;									//用于分页画地图
protected:
	std::vector<VecPosition> vecList;
	const VecPosition *curPosition;
	bool isBinded;
	RePlayView*drawView;
	double mapLength;
	std::string folder;								//地图图片文件夹
	double width;
	double height;
   


	int setTransparent(bool isTransparent);							//将replayerView设置为透明
	bool isWillShow(const VecPosition &position, const VecPosition &size)const;
	void folderToPartView(LPCTSTR pImgFile,double viewSizeX,double viewSizeY,int fps=8											
	);
	
	int onCreate();
	
	VecPosition g2l(const VecPosition &g)const;								//地图坐标与镜头坐标的转换
};

