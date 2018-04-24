#pragma once
#pragma execution_character_set("utf-8")
#include<vector>
#include<graphics.h>
#include"View.h"
#include"VecPosition.h"


/**
		循环显示的VIEW，类似gif
		可设置播放次数和播放
*/
class RePlayView :public View
{
protected:
	std::vector<IMAGE> imgs;		//此vector存储了每一帧的图片
	std::vector<int> imgFps;		//每一帧图片显示多少fps
	std::vector<int> FpsSumTop;		//前n-1帧的总fps		
	std::vector<int> FpsSumEnd;		//从后向前的fps
	int fpsSum;						//img的总fps
	bool isFirstDraw;				//是否是第一次draw
	long long firstDrawFps;			//第一次画此View时刻
	long long drawedFps;			//此view从开始显示到现在经历了多少fps
	long long drawTimes;			//画图总次数
	UINT TransPerantColor;			//bmp文件的透明颜色
	int onCreate();					//在view创建时执行

	int getSum(int n);											//得到前n+1帧的fps总和
	int getSumForEnd(int n);									//得到第n+1帧到最后一帧的fps总和
public:
	bool isLoop;					//是否循环显示
	bool isSequence;				//是否顺序输出
	bool isTransparent;				//是否是透明图片
	RePlayView();												//默认位置（0，0），默认大小100x100		
	RePlayView(double x, double y, double width, double height);//初始化设置位置与大小
	RePlayView(double width, double height);
	RePlayView(double width, double height, UINT color);		//位置与透明颜色
	int init();													//重置
	RePlayView* addIMAGE(IMAGE img, int imgFps);						//添加IMAGE并指定帧数
	RePlayView* addIMAGE(IMAGE img);									//按默认fps添加
	int getFpsSum();											//得到所有img的fps总和
	int update();
	View* draw();												//按初始化时的位置大小画图
	View* draw(VecPosition *position);							//按初始化时的位置大小画图
	View* draw(double x, double y);								//大小不变，指定位置画图
	View* draw(double x, double y, double width, double height);
	View* draw(const VecPosition&p);
	int getImgSum();
	int setFps(unsigned int i, int fps);
	
};