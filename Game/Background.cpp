
#include <graphics.h>
#include "Background.h"
#include"Debug.h"
#include"RePlayView.h"
#include"main.h"
#include"Water.h"
#include"Stone.h"
#include"Grass.h"
#include"HJW.h"
#include"AddTree.h"
#include"Mountain1.h"
#include"Mountain2.h"
#include"AddWave.h"
#include"BigTree1.h"
#include"GrassOfTree.h"
#include"Trunk.h"

const int Background::MOVE = 0;

double Background::getMapLength()
{
	double max = 0;
	for (unsigned int i = 0; i < partViewList.size(); i++)
	{
		double t = partViewList[i]->getMapMax();
		if (t > max) max = t;
	}
	return max;
}

double Background::getMapX()
{
	return curPosition->getX();
}



bool Background::mapIsComeToEnd()
{
	return getMapLength()-getMapX()<=srcWidth+1;
}

Background::Background():mapLength(0),sumFps(0)
{
	curPosition = new VecPosition(0, 0);
	debug.GameLog("Background Created!");
	onCreate();
	bindCurX();
	mapLength = getMapLength();
}

Background::~Background()
{
	delete curPosition;
	for (unsigned int i = 0; i < partViewList.size(); i++)
		delete partViewList[i];
}

int Background::move(int x)
{
	curPosition->setX(curPosition->getX() + x);
	if (curPosition->getX() < 0) curPosition->setX(0);
	if (curPosition->getX() > mapLength-srcWidth) curPosition->setX(mapLength-srcWidth);
	return 0;
}

void Background::addPartView(PartView * pv)
{
	partViewList.push_back(pv);
}

int Background::message(int type, int value)
{
	if (type == MOVE)
		move(value);
	return 0;
}

int Background::bindCurX()
{
	for (unsigned int i = 0; i < partViewList.size(); i++)
		partViewList[i]->bindCurPosition(curPosition);
	return 0;
}

void Background::tree()
{

	PartView* tree1 = new PartView(80, 70, "tree1");
	PartView* tree2 = new PartView(80, 70, "tree2");
	PartView* tree3 = new PartView(80, 70, "tree3");
	AddTree addTree;
	std::vector<PartView*> list;
	list.push_back(tree1);
	list.push_back(tree2);
	list.push_back(tree3);
	addTree.addPartView(list);			//addTree对象将数据填进PartView内
	addPartView(tree1);
	addPartView(tree3);
	addPartView(tree2);
}

void Background::wave()
{
	IMAGE waves;
	SourceToImg(&waves, "IMAGE", "WAVE", 40 * 6, 40 * 4);
	IMAGE**imgs = cutIMAGE(&waves, 4, 6, 40, 40);

	//1
	{
		RePlayView* Rwave1 = new RePlayView(40, 40, 0xAAAAAA);
		Rwave1->addIMAGE(imgs[0][0], 8)->addIMAGE(imgs[2][0], 8);
		PartView* wave1 = new PartView(40, 40, Rwave1);
		wave1->addPosition(40, 360)->page=3;
		wave1->addPosition(280, 360)->page=4;
		wave1->addPosition(360, 355);
		addPartView(wave1);
	}

	//5
	{
		RePlayView* Rwave5 = new RePlayView(40, 40, 0xAAAAAA);
		Rwave5->addIMAGE(imgs[0][1], 8)->addIMAGE(imgs[2][1], 8);
		PartView* wave5 = new PartView(40, 40, Rwave5);
		wave5->page = 1;
		wave5->addPosition(40, 420)->page=2;
		wave5->addPosition(200, 420)->page=5;
		wave5->addPosition(280, 420)->page=6;
		wave5->addPosition(440, 420);
		addPartView(wave5);
	}
	
	//2
	{
		std::vector<RePlayView*> VRwave2;
		std::vector<PartView*> VPwave2;
		for (int i = 0; i < 3; i++)
		{
			VRwave2.push_back(new RePlayView(40, 40, 0xAAAAAA));
			VRwave2[i]->addIMAGE(imgs[1][i + 1], 8)->addIMAGE(imgs[3][i + 1], 8);
			VPwave2.push_back(new PartView(40, 40, VRwave2[i]));
		}
		AddWave addWave;
		addWave.addPartView(VPwave2);
		for (int i = 0; i < 3; i++)
			addPartView(VPwave2[i]);

		
	}
	
	//4
	{
		RePlayView* Rwave4 = new RePlayView(40, 40, 0xAAAAAA);
		Rwave4->addIMAGE(imgs[0][5], 8)->addIMAGE(imgs[2][5], 8);
		PartView* wave4 = new PartView(40, 40, Rwave4);
		wave4->addPosition(360, 400)->page = 1;
		wave4->addPosition(360, 395)->page = 2;
		wave4->addPosition(120, 395)->page=4;
		wave4->addPosition(520, 395)->page=6;
		wave4->addPosition(120, 395)->addPosition(560,460);
		addPartView(wave4);
	}

	//3
	{
		RePlayView* Rwave3 = new RePlayView(40, 40, 0xAAAAAA);
		Rwave3->addIMAGE(imgs[1][0], 8)->addIMAGE(imgs[3][0], 8);
		PartView* wave3 = new PartView(40, 40, Rwave3);
		wave3->addPosition(40, 400)->addPosition(360, 430)->page = 1;
		wave3->addPosition(40, 460)->addPosition(360, 435)->page = 2;
		wave3->addPosition(120, 430)->addPosition(200, 460)->page=3;
		wave3->addPosition(280, 400)->page=4;
		wave3->addPosition(520, 430)->page=5;
		wave3->addPosition(280, 460)->page=6;
		wave3->addPosition(120, 430)->addPosition(440,460);
		addPartView(wave3);
	}
	
	//6
	{
		RePlayView* Rwave6 = new RePlayView(40, 40, 0xAAAAAA);
		Rwave6->addIMAGE(imgs[1][4], 8)->addIMAGE(imgs[3][4], 8);
		PartView* wave6 = new PartView(40, 40, Rwave6);
		wave6->page = 1;
		wave6->addPosition(240, 460)->addPosition(320, 430)->addPosition(560, 435)->page = 2;
		wave6->addPosition(400, 465)->addPosition(560,430)->addPosition(640,395)->page=4;
		wave6->addPosition(80, 400)->page=5;
		wave6->addPosition(560, 460)->page=6;
		wave6->addPosition(80, 430);
		addPartView(wave6);
	}
	
	//7
	{
		RePlayView* Rwave7 = new RePlayView(40, 40, 0xAAAAAA);
		Rwave7->addIMAGE(imgs[0][3], 8)->addIMAGE(imgs[2][3], 8);
		PartView* wave7 = new PartView(40, 40, Rwave7);
		wave7->page = 1;
		wave7->addPosition(240, 420)->page = 2;
		wave7->addPosition(400, 420)->page=5;
		wave7->addPosition(560, 420);
		addPartView(wave7);
	}
	
	//8
	{
		RePlayView* Rwave8 = new RePlayView(40, 40, 0xAAAAAA);
		Rwave8->addIMAGE(imgs[1][5], 8)->addIMAGE(imgs[3][5], 8);
		PartView* wave8 = new PartView(40, 40, Rwave8);
		wave8->page = 1;
		wave8->addPosition(320, 395)->addPosition(560, 395)->page=2;
		wave8->addPosition(560, 395)->page = 6;
		wave8->addPosition(80, 395);
		addPartView(wave8);
	}

	//9
	{
		RePlayView* Rwave9 = new RePlayView(40, 40, 0xAAAAAA);
		Rwave9->addIMAGE(imgs[0][4], 8)->addIMAGE(imgs[2][4], 8);
		PartView* wave9 = new PartView(40, 40, Rwave9);
		wave9->page = 3;
		wave9->addPosition(0, 355)->page=4;
		wave9->addPosition(80, 360);
		addPartView(wave9);
	}
	for (int i = 0; i < 4; i++)
		delete[] imgs[i];
	delete[]imgs;
}

int Background::onCreate()
{
	PartView *water;
	addPartView(new Stars());
	addPartView(water=new Water());
	addPartView(new Trunk());
	addPartView(new Stone());
	PartView*grass;
	addPartView(grass=new Grass());
	tree();
	addPartView(new Mountain1());
	addPartView(new Mountain2());
	wave();
	
	addPartView(new GrassOfTree());
	addPartView(new BigTree1());

	grassVecList = grass->getVecList();
	waterVecList = water->getVecList();
	return 0;
}



View* Background::draw()
{
	//curPosition->setX(640*12);
	for (unsigned int i = 0; i < partViewList.size(); i++)
		partViewList[i]->draw();
	return 0;
}
