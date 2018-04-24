#include "StartActivityView.h"
#include"Application.h"
#include "main.h"
#include "Debug.h"



View* StartActivittyView::draw()
{
	
	int padingLeft = srcWidth / 10;
	int padingTop = srcHeight / 10;
	if (createFpsSum > 1000000) createFpsSum = 100;								// 防止开游戏太长时间导致溢出
	if (createFpsSum <= gradientImgs.getImgFpsSum()&&endFps<=0)							//进入游戏的渐现过程
		putimage(padingLeft, padingTop, gradientImgs.getInIMAGE(createFpsSum));
	else if (endFps > 0)														//退出界面的渐隐过程
	{
		putimage(padingLeft, padingTop, gradientImgs.getOutIMAGE(endFps--));
		
		if (endFps <= 0)
		{
			application->setActivity(1);
		}
			

	}else
	{
		long tempFpsSum = createFpsSum-gradientImgs.getImgFpsSum();
		putimage(padingLeft, padingTop, runImgs.getIMAGE(tempFpsSum%runImgs.getImgFpsSum()));
	}
	createFpsSum++;
	return this;
}

int StartActivittyView::onCreate()
{
	
	Img tempImg;
	IMAGE tempIMAGE;
	std::string folder = "image\\title\\";
	std::string runTimeImgPath[4] = { "title13_6.bmp" ,"title14_8.bmp" ,"title15_8.bmp","title16_8.bmp" };
	int imgWidth = srcWidth*8/10;
	int imgHeight = srcHeight*8/10;
	for (int i = 0; i < 4; i++)
	{
		loadimage(&tempIMAGE,(folder+runTimeImgPath[i]).c_str(),imgWidth,imgHeight);
		runImgs.addImg(tempIMAGE, i==0?6:8);
	}
	std::string gradientImgPath[12] = { "title1_6.bmp", "title2_2.bmp", "title3_6.bmp", "title4_2.bmp", "title5_6.bmp","title6_2.bmp",
									"title7_6.bmp", "title8_2.bmp", "ttitle9_6.bmp", "title10_2.bmp", "title11_6.bmp", "title12_2.bmp" };
	for (int i = 0; i < 12; i++)
	{
		loadimage(&tempIMAGE,(folder+ gradientImgPath[i]).c_str(), imgWidth, imgHeight);
		gradientImgs.addImg(tempIMAGE, i % 2 == 0 ? 6 : 2);
	}
	
	return 0;
}


StartActivittyView::StartActivittyView()
{
	debug.GameLog("StartActivityView Created!");
	createFpsSum = 0;
	endFps = 0;
	onCreate();
	
}

StartActivittyView::~StartActivittyView()
{

}


