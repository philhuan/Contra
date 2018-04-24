#pragma once
#pragma execution_character_set("utf-8")
#include "Physical.h"
#include "Area.h"
#include "Bill.h"

class TheCannonFodder:public Physical
{
public:
	TheCannonFodder(const VecPosition& position,bool isRight=true);
	~TheCannonFodder();
	const VecPosition& getPosition();
	void run();
	
private:
	bool isLand();
	bool directionIsRight;
	bool frontIsNotRoad;
	VecPosition position;
	Area *myFootArea;
	std::vector<Area*> *grassArea;
};

