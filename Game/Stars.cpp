#include "Stars.h"
#include"main.h"
#include"HJW.h"
Stars::Stars()
{
	
	starSize = VecPosition(12 ,12);
	drawView = new RePlayView(0, 0, starSize.getX(),starSize.getY());
	IMAGE tIMG;
	for (int i = 0; i < 2; i++)			//µ¥¿ÅÐÇÐÇÍ¼Æ¬ÔØÈë
	{
		SourceToImg(&tIMG, "IMAGE","star", starSize.getX(), 2 * starSize.getY());
		SetWorkingImage(&tIMG);
		IMAGE p;
		getImg(&p, 0, i * starSize.getY(), starSize.getX(), starSize.getY());
		drawView->addIMAGE(p, 8);
	}
	SetWorkingImage();
	onCreate();
}

int Stars::onCreate()
{
	
	page = 0;
	{
		int a[][2] = {
			{ 10,60 },{ 10,130 },
			{ 30,45 },{ 30,110 },
			{ 50,60 },
			{ 70,40 },{ 70,80 },{ 70,95 },{ 70,145 },
			{ 90,60 },
			{ 110,40 },
			{ 150,25 },{ 150,80 },
			{ 170,60 },
			{ 190,40 },
			{ 210,60 },
			{ 230,40 },{ 230,80 },
			{ 250,60 },
			{ 270,25 },
			{ 290,40 },
			{ 330,25 },
			{ 350,45 },
			{ 410,25 },
			{ 450,410 },
			{ 490,25 },
			{ 510,40 },
			{ 610,40 },
			{ 630,80 }
		};
		addPosition(a, sizeof(a) / sizeof(int) / 2);
	}
	page = 1;
	{
		int a[][2] = {
			{10,60},
			{30,45},
			{50,60},
			{70,45},{70,80},
			{90,60},
			{110,45},
			{150,25},{150,80},
			{170,60},
			{190,30},
			{210,45},
			{245,30},
			{265,45},
			{330,30},
			{365,45},
			{405,30},
			{425,45},
			{485,30},
			{525,45},
			{565,30},
			{585,45}
		};
		addPosition(a, sizeof(a) / sizeof(int) / 2);
	}
	page = 2;
	{
		int a[][2] = {
			{10,25},{170,25},{250,25},
			{110,45},{210,45},{ 270 ,45},{370,45},{510,45},{550,45},
			{490,60},{530,60},
			{390,77},{550,77},
			{550,95},
			{430,110},{470,110},{510,110},
			{410,130},{450,130},{490,130},
			{470,140},{550,140}
		};
		addPosition(a, sizeof(a) / sizeof(int) / 2);
	}
	page = 3;
	{
		int a[][2] = {
			{150,25},{390,25},{470,25},
			{30,45},{67,45},{110,45 },{265,45 },{308,45 },{346,45 },{430,45 },{590,45 },{630,45},
			{10,60},{50,60},{90,60},{250,60},{300,60},{330,60},{410,60},{570,60},{610,60},
			{70,80},{150,80},{310,80},{390,80},{470,80},{630,80},
			{310,95},
			{190,112},{230,112},{270,112},{350,112},{390,112},{430,112},{470,112},
			{170,130},{210,130},{250,130},{330,130},{370,130},{410,130},{450,130},
			{230,145},{310,145},{390,145},{410,145},
			{150,160},
			{110,180},
			{90,200},
			{150,215}

		};
		addPosition(a, sizeof(a) / sizeof(int) / 2);
	}
	page = 4;
	{
		{
			int y = 25;
			int list1[] = {
				310,550,590
			};
			addStar(list1, y, sizeof(list1) / sizeof(int));
		}

		{
			int y = 45;
			int list1[] = {
				270,350,390,510,610
			};
			addStar(list1, y, sizeof(list1) / sizeof(int));
		}

		{
			int y = 60;
			int list1[] = {
				250,330,370,490,570
			};
			addStar(list1, y, sizeof(list1) / sizeof(int));
		}

		{
			int y = 77;
			int list1[] = {
				310,390
			};
			addStar(list1, y, sizeof(list1) / sizeof(int));
		}

		{
			int y = 95;
			int list1[] = {
				70,150
			};
			addStar(list1, y, sizeof(list1) / sizeof(int));
		}
		
		{
			int y = 110;
			int list1[] = {
				30,110,270,310
			};
			addStar(list1, y, sizeof(list1) / sizeof(int));
		}

		{
			int y = 130;
			int list1[] = {
				10,90,250,290
			};
			addStar(list1, y, sizeof(list1) / sizeof(int));
		}

		{
			int y = 145;
			int list1[] = {
				70,150,310
			};
			addStar(list1, y, sizeof(list1) / sizeof(int));
		}
	}
	page = 5;
	{
		addPosition(25, 225);
		{
			int y = 45;
			int list1[] = {
				30,130,190
			};
			addStar(list1, y, sizeof(list1) / sizeof(int));
		}
		addPosition(170, 60);
		addPosition(145, 75);
		addPosition(225, 75);
		addPosition(190, 110);
		addPosition(225, 110);
		addPosition(225, 145);
		{
			int y = 130;
			int list1[] = {
				170,210
			};
			addStar(list1, y, sizeof(list1) / sizeof(int));
		}
	}

	return 0;
}

Stars::~Stars()
{
}

PartView * Stars::addStar(int a[], int y, int size)
{
	for (int i = 0; i < size; i++)
	{
		addPosition(a[i], y);
	}

	return this;
}



