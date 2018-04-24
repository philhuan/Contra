#include "TheCannonFodder.h"
#include "GameActivity.h"

TheCannonFodder::TheCannonFodder(const VecPosition & position, bool isRight) :
	directionIsRight(isRight), frontIsNotRoad(false),position(position)
{
}

TheCannonFodder::~TheCannonFodder()
{
}

const VecPosition & TheCannonFodder::getPosition()
{
	return position;
}

void TheCannonFodder::run()
{
	static bool isFirst;
	if (isFirst == false)
	{
		/*std::vector<VecPosition> grassVecList = gameActivity->backGround->grassVecList;
		for (unsigned int i = 0; i < grassVecList.size(); i++)
		{
			grassArea->push_back(new Area(grassVecList[i].getX(), grassVecList[i].getY(), 80, 5));
		}
		if (directionX == RIGHT)
			myFootArea = new Area(position.getX() + 10, position.getY() + 70, 10, 10);
		else
			myFootArea = new Area(position.getX() + 5, position.getY() + 70, 10, 10);
		isFirst = true;*/
	}
	myFootArea->setPositionX(gameActivity->backGround->curPosition->getX() + position.getX() + 30);
	myFootArea->setPositionY(position.getY() + (directionIsRight?10:5));

	Velocity += Acceleration;
	position += Velocity;
	if (frontIsNotRoad)
	{
		Velocity.setY(-8);
	}

}

bool TheCannonFodder::isLand()
{
	/*for (unsigned int i = 0; i < grassArea->size(); i++)
	{
		if (myFootArea->isIntersect(*(grassArea[i])))
			return true;
	}
	if (position.getY() >= 400) return true;*/
	return false;
}
