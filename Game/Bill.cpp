#include "Bill.h"
#include"Debug.h"
#include"HJW.h"
#include"main.h"
#include"GameActivity.h"
#include"HJW.h"
int Bill::TX=0;
int Bill::TY=1;
int Bill::M_SHOOT=2;
int Bill::M_JUMP=3;

Bill::Bill() :
View(200, 200, 40, 100), isShooting(false),
act(STAND), directionX(RIGHT),directionY(Y_NULL)
{
	//setA(VecPosition(0,0.1));
	
	onCreate();
}


int Bill::onCreate()
{
	position.setX(105)->setY(156);
	billBullets = new Bullets();
	standRight = new RePlayView(60, 75, 0xAAAAAA);
	{
		IMAGE tStandImg;
		SourceToImg(&tStandImg, "IMAGE", "STAND_RIGHT", 60, 75);
		standRight->addIMAGE(tStandImg, 8);
	}

	standLeft = new RePlayView(60, 75, 0xAAAAAA);
	{
		IMAGE t;
		SourceToImg(&t, "IMAGE", "STAND_LEFT", 60, 75);
		standLeft->addIMAGE(t, 8);
	}
	inWaterShootLeft=new RePlayView(60, 75, 0xAAAAAA);
	inWaterShootRight=new RePlayView(60, 75, 0xAAAAAA);
	inWaterRight = new RePlayView(60, 75, 0xAAAAAA);
	inWaterLeft = new RePlayView(60, 75, 0xAAAAAA);
	dive = new RePlayView(60, 75, 0xAAAAAA);
	{
		IMAGE tImg;
		SourceToImg(&tImg, "IMAGE", "IN_WATER", 300, 75);
		IMAGE**tImgs = cutIMAGE(&tImg, 1, 5, 60, 75);
		inWaterShootLeft->addIMAGE(tImgs[0][0], 8);
		inWaterLeft->addIMAGE(tImgs[0][1], 8);
		dive->addIMAGE(tImgs[0][2], 8);
		inWaterRight->addIMAGE(tImgs[0][3], 8);
		inWaterShootRight->addIMAGE(tImgs[0][4], 8);
		delete[]tImgs[0];
		delete[]tImgs;
	}

	inWaterShootUp_right = new RePlayView(60, 75,0xAAAAAA);
	inWaterShootUp_left = new RePlayView(60, 75, 0xAAAAAA);
	inWaterShootUpLeft = new RePlayView(60, 75, 0xAAAAAA);
	inWaterShootUpRight = new RePlayView(60, 75, 0xAAAAAA);
	{
		IMAGE tImg;
		SourceToImg(&tImg, "IMAGE", "IN_WATER_UP", 240, 75);
		IMAGE**tImgs = cutIMAGE(&tImg, 1, 4, 60, 75);
		inWaterShootUpRight->addIMAGE(tImgs[0][0], 8);
		inWaterShootUp_right->addIMAGE(tImgs[0][1], 8);
		inWaterShootUpLeft->addIMAGE(tImgs[0][2], 8);
		inWaterShootUp_left->addIMAGE(tImgs[0][3], 8);
		delete[]tImgs[0];
		delete[]tImgs;
	}

	standShootRight = new RePlayView(60, 75, 0xAAAAAA);
	{
		IMAGE t;
		SourceToImg(&t, "IMAGE", "STAND_SHOOT_RIGHT", 60, 75);
		standShootRight->addIMAGE(t, 8);
	}

	standShootLeft = new RePlayView(60, 75, 0xAAAAAA);
	{
		IMAGE t;
		SourceToImg(&t, "IMAGE", "STAND_SHOOT_LEFT", 60, 75);
		standShootLeft->addIMAGE(t, 8);
	}

	walkRight = new RePlayView(60, 75, 0xAAAAAA);
	{
		IMAGE tImg;
		SourceToImg(&tImg, "IMAGE", "BILL_RUN_RIGHT", 300, 75);
		IMAGE**tImgs = cutIMAGE(&tImg, 1, 5, 60, 75);
		for (int i = 0; i < 5; i++)
		{
			walkRight->addIMAGE(tImgs[0][i], 8);
			
		}
		delete []tImgs[0];
		delete []tImgs;
	}

	walkLeft = new RePlayView(60, 75, 0xAAAAAA);
	{
		
		IMAGE tImg;
		SourceToImg(&tImg, "IMAGE", "BILL_RUN_LEFT", 300, 75);
		IMAGE**tImgs = cutIMAGE(&tImg, 1, 5, 60, 75);
		for (int i = 0; i < 5; i++)
		{
			walkLeft->addIMAGE(tImgs[0][i], 8);
		}
		delete[]tImgs[0];
		delete[]tImgs;
	}
	
	walkShootLeftUp = new RePlayView(60, 75, 0xAAAAAA);
	{
		IMAGE t;
		SourceToImg(&t, "IMAGE", "WALK_SHOOT_LEFTUP",180,75);
		IMAGE**imgs = cutIMAGE(&t, 1, 3, 60, 75);
		for (int i = 0; i < 3; i++)
		{
			walkShootLeftUp->addIMAGE(imgs[0][i], 8);
		}
		delete[]imgs[0];
		delete[]imgs;
	}

	walkShootRightUp = new RePlayView(60, 75, 0xAAAAAA);
	{
		IMAGE t;
		SourceToImg(&t, "IMAGE", "WALK_SHOOT_RIGHTUP", 180, 75);
		IMAGE**imgs = cutIMAGE(&t, 1, 3, 60, 75);
		for (int i = 0; i < 3; i++)
			walkShootRightUp->addIMAGE(imgs[0][i], 8);
			delete[] imgs[0];
		delete[]imgs;
	}

	walkShootRight=new RePlayView(60, 75, 0xAAAAAA);
	{
		IMAGE t;
		SourceToImg(&t, "IMAGE", "WALK_SHOOT_RIGHT", 180, 75);
		IMAGE**imgs = cutIMAGE(&t, 1, 3, 60, 75);
		for (int i = 0; i < 3; i++)
			walkShootRight->addIMAGE(imgs[0][i], 8);
		delete[] imgs[0];
		delete[]imgs;
	}
	walkShootLeft=new RePlayView(60, 75, 0xAAAAAA);
	{
		IMAGE t;
		SourceToImg(&t, "IMAGE", "WALK_SHOOT_LEFT", 180, 75);
		IMAGE**imgs = cutIMAGE(&t, 1, 3, 60, 75);
		for (int i = 0; i < 3; i++)
			walkShootLeft->addIMAGE(imgs[0][2-i], 8);
		delete[] imgs[0];
		delete[]imgs;
	}

	jumpLeft = new RePlayView(60, 60, 0xAAAAAA);
	jumpRight = new RePlayView(60, 60, 0xAAAAAA);
	{
		IMAGE t;
		SourceToImg(&t, "IMAGE", "BILL_JUMP", 480, 60);
		IMAGE**imgs = cutIMAGE(&t, 1, 8, 60, 60);
		for (int i = 3; i >0; i--)
			jumpLeft->addIMAGE(imgs[0][i], 4);
		for (int i = 4; i < 8; i++)
			jumpRight->addIMAGE(imgs[0][i], 4);
		delete[] imgs[0];
		delete[]imgs;
	}

	walkShootLeftDown = new RePlayView(60, 75, 0xAAAAAA);
	walkShootRightDown = new RePlayView(60, 75, 0xAAAAAA);
	{
		IMAGE t;
		SourceToImg(&t, "IMAGE", "WALK_SHOOT_DOWNRIGHTLEFT", 360, 75);
		IMAGE**imgs = cutIMAGE(&t, 1, 6, 60, 75);
		for (int i = 0; i < 3; i++)
			walkShootLeftDown->addIMAGE(imgs[0][i], 8);
		for (int i = 3; i < 6; i++)
			walkShootRightDown->addIMAGE(imgs[0][i], 8);
		delete[]imgs[0];
		delete[]imgs;
	}

	getDownLeft = new RePlayView(84, 75, 0xAAAAAA);
	getDownRight = new RePlayView(84, 75, 0xAAAAAA);
	{
		IMAGE t;
		SourceToImg(&t, "IMAGE", "GETDOWN", 168, 75);
		IMAGE**imgs = cutIMAGE(&t, 1, 2, 84, 75);
		getDownLeft->addIMAGE(imgs[0][0],8);
		getDownRight->addIMAGE(imgs[0][1],8);
		delete[]imgs[0];
		delete[]imgs;
	}

	shootUpLeft = new RePlayView(60, 100, 0xAAAAAA);
	shootUpRight = new RePlayView(60, 100, 0xAAAAAA);
	{
		IMAGE t;
		SourceToImg(&t, "IMAGE", "SHOOT_UP", 120, 100);
		IMAGE**imgs = cutIMAGE(&t, 1, 2, 60, 100);
		shootUpRight->addIMAGE(imgs[0][0], 8);
		shootUpLeft->addIMAGE(imgs[0][1], 8);
		delete[]imgs[0];
		delete[]imgs;
	}

	standUpRight = new RePlayView(60, 100, 0xAAAAAA);
	standUpLeft = new RePlayView(60, 100, 0xAAAAAA);
	{
		IMAGE t;
		SourceToImg(&t, "IMAGE", "STAND_UP", 120, 100);
		IMAGE**imgs = cutIMAGE(&t, 1, 2, 60, 100);
		standUpRight->addIMAGE(imgs[0][0], 8);
		standUpLeft->addIMAGE(imgs[0][1], 8);
		delete[]imgs[0];
		delete[]imgs;
	}
	return 0;
}

bool Bill::isTouchLand()
{
	for (unsigned int i = 0; i < grassVecList.size(); i++)
	{
		if (grassVecList[i].getY() > 400)
		{
			if (myArea->isIntersect(*grassArea[i]))
				return true;
		}
			//return true;
	}
	return false;
}

View * Bill::draw()
{
	physical();
	if (isJump)
	{
		if (directionX == RIGHT)
		{
			jumpRight->draw(position);
		}
		else
		{
			jumpLeft->draw(position);
		}
	}
	else
	switch (act)
	{
	case STAND:
	{
		//开枪时
		if (gameTime - lastShootTime <= 12.0 / 60
			&&fmod(gameTime - lastShootTime,12.0/60)<=6.0/60)
		{
			switch (directionY)
			{
			case UP:
			{
				if (directionX == RIGHT)
					shootUpRight->draw(position - VecPosition(10, 26));
				else if (directionX == LEFT)
					shootUpLeft->draw(position - VecPosition(-10, 26));
				break;
			}
			case DOWN:
			{
				if (directionX == RIGHT)
					getDownRight->draw(position - VecPosition(0, 1));
				else if (directionX == LEFT)
					getDownLeft->draw(position - VecPosition(0, 1));
				break;
			}
			case Y_NULL:
			{
				if (directionX == RIGHT)
					standShootRight->draw(position);
				else if (directionX == LEFT)
					standShootLeft->draw(position);
				break;
			}
			default:
				break;
			}
			//开枪状态维持4帧
			{
				static int count;
				if (count++ == 4)
				{
					isShooting = false;
					count = 0;
				}
			}
		}
		else//没开枪
		{
			switch (directionY)
			{
			case UP:
			{
				if (directionX == RIGHT)
					standUpRight->draw(position - VecPosition(10, 26));
				else if (directionX == LEFT)
					standUpLeft->draw(position - VecPosition(-10, 26));
				break;
			}
			case DOWN:
			{
				if (directionX == RIGHT)
					getDownRight->draw(position);
				else if (directionX == LEFT)
					getDownLeft->draw(position);
				break;
			}
			case Y_NULL:
			{
				if (directionX == RIGHT)
					standRight->draw(position);
				else if (directionX == LEFT)
					standLeft->draw(position);
				break;
			}
			default:
				break;
			}
		}

		break;
	}
	case WALK:
	{
		if (directionY == UP)
		{
			if (directionX == RIGHT)
				walkShootRightUp->draw(position);
			if (directionX == LEFT)
				walkShootLeftUp->draw(position);

		}
		else if (directionY == DOWN)
		{
			if (directionX == RIGHT)
				walkShootRightDown->draw(position);
			if (directionX == LEFT)
				walkShootLeftDown->draw(position);
		}
		else
		{
			if (gameTime - lastShootTime <= 12.0 / 60)
			{
				if (directionX == RIGHT)
					walkShootRight->draw(position);
				if (directionX == LEFT)
					walkShootLeft->draw(position);
			}
			else
			{
				if (directionX == RIGHT)
					walkRight->draw(position);
				if (directionX == LEFT)
					walkLeft->draw(position);
			}

		}
	break;
	}
	case INWATER:
	{
		if (isDive)
		{
			dive->draw(position);
		}
		else
		{
			if (gameTime - lastShootTime <= 12.0 / 60)
			{
				if (directionY == UP)
				{
					if (isMoving)
					{
						if (directionX == RIGHT)
						{
							inWaterShootUpRight->draw(position.getX() + 10, position.getY()-20);
						}
						else
						{
							inWaterShootUpLeft->draw(position.getX() + 10, position.getY() - 20);
						}
					}
					else
					{
						if (directionX == RIGHT)
						{
							inWaterShootUp_right->draw(position.getX() , position.getY()-20);
						}
						else
						{
							inWaterShootUp_left->draw(position.getX(), position.getY() - 20);
						}
					}
					
				}
				else
				{
					if (directionX == RIGHT)
					{
						inWaterShootRight->draw(position.getX() + 10, position.getY());
					}
					else
					{
						inWaterShootLeft->draw(position);
					}
				}
				
			}
			else
			{
				if (directionX == RIGHT)
				{
					inWaterRight->draw(position);
				}
				else
				{
					inWaterLeft->draw(position);
				}
			}
			
		}
		break;
	}
	default:
		break;
	}
	
	
	
	billBullets->draw();
	isMoving = false;
	act = STAND;
	isShooting = false;
	directionY = Y_NULL;
	return this;
}

void Bill::physical()
{

	if (position.getY() > 375&&position.getX()+gameActivity->backGround->curPosition->getX()<4500)
		act = INWATER;
	//this will toggle the isDive property,test test test test
	if (act == INWATER && directionY == DOWN)
		isDive = true;
	else
		isDive = false;
	if (isTouchLand())
	{
		act = STAND;
		if (directionX == RIGHT) position += VecPosition(30, -30);
		else position += VecPosition(-30, -40);
	}
	static bool isFirst;
	if (isFirst == false)
	{
		waterVecList = gameActivity->backGround->waterVecList;
		grassVecList = gameActivity->backGround->grassVecList;
		for (unsigned int i = 0; i < grassVecList.size(); i++)
		{
			grassArea.push_back(new Area(grassVecList[i].getX(), grassVecList[i].getY() , 80, 5));
		}
		if(directionX==RIGHT)
			myFootArea = new Area(position.getX()+15 , position.getY() + 70, 20, 25);
		else
			myFootArea = new Area(position.getX() + 30, position.getY() + 70, 20, 25);
		//myFootArea = new Area(position.getX() + 25, position.getY() + 70, 20, 25);
		myArea = new Area(position, VecPosition(60, 30));
		isFirst = true;
	}
	myFootArea->setPositionX(gameActivity->backGround->curPosition->getX() + position.getX()+25);
	myFootArea->setPositionY(position.getY()+50);
	myArea->setPositionX(gameActivity->backGround->curPosition->getX() + position.getX());
	myArea->setPositionY(gameActivity->backGround->curPosition->getY() + position.getY());
	Velocity += getA();
	position += Velocity;
	Acceleration.setY(0.5);
	if (isLand()&&jumpAct==j_DOWN)
	{
		Velocity.setY(0);
		Acceleration.setY(0);
		isJump = false;
		//position.setY(position.getY() - 2);
		
	}
	if (Velocity.getY() > 0) jumpAct = j_DOWN;
	if (Velocity.getY() < 0) jumpAct = j_UP;

	if (position.getX() + gameActivity->backGround->curPosition->getX() > 4500)
		if (position.getY() > 400) position.setX(100)->setY(100);

}

int Bill::message(int type, int value)
{
	if (type == TX)
	{
		isMoving = true;
		act = WALK;
		if (value > 0)
		{
			directionX = RIGHT;
			setPositionX(getPositionX() + 3);
		}
		if (value < 0)
		{
			directionX = LEFT;
			setPositionX(getPositionX() - 3);
		}

		if (getPosition().getX() < 0) setPositionX(0);
		if (((int)getPositionX()) % srcWidth >= srcWidth / 2)
		{
			if (gameActivity->backGround->mapIsComeToEnd() && getPosition().getX() < srcWidth - 10)
				return 0;
			setPositionX(getPositionX() - 3);
			gameActivity->moveBackground(3);
		}
	}
	else if (type == TY)
	{

		if (value < 0)
		{
			directionY = UP;
		}
		else if (value > 0)
		{
			directionY = DOWN;
		}
		//position -= VecPosition(0, -value);


		if (getPosition().getY() < 0) setPositionY(0);
		if (getPosition().getY() - 80 > srcHeight) setPositionY(srcHeight + 80);
	}
	else if (type == M_SHOOT)
	{

		if (position.getY() > 375 && position.getX() + gameActivity->backGround->curPosition->getX() < 4500)
			act = INWATER;
		static double alastShootTime;
		if (gameTime - alastShootTime > 12.0 / 60)
		{
			if (isMoving)
			{

				if (directionX == RIGHT)
				{
					if (directionY == UP)
						billBullets->createBullut(position.getX() + (act == INWATER ? 50 : 40), position.getY(), BULLET_RIGHT_UP);
					else if (directionY == DOWN)
						billBullets->createBullut(position.getX() + 40, position.getY() + 40, BULLET_RIGHT_DOWN);
					else
						billBullets->createBullut(position.getX() + 60, position.getY() + 22, BULLET_RIGHT);
				}

				else if (directionX == LEFT)
				{
					if (directionY == UP)
						billBullets->createBullut(position.getX() + (act == INWATER ? 10 : 0), position.getY(), BULLET_LEFT_UP);
					else if (directionY == DOWN)
						billBullets->createBullut(position.getX(), position.getY() + 40, BULLET_LEFT_DOWN);
					else
						billBullets->createBullut(position.getX(), position.getY() + 22, BULLET_LEFT);
				}
			}
			else
			{
				if (directionY == UP)
				{
					if (directionX == RIGHT)
						billBullets->createBullut(position.getX() + (act == INWATER ? 35 : 25), position.getY() - 10, BULLET_UP);
					else
						billBullets->createBullut(position.getX() + (act == INWATER ? 15 : 25), position.getY() - 10, BULLET_UP);
				}
				else if (directionY == DOWN)
				{
					if (directionX == RIGHT)
						billBullets->createBullut(position.getX() + 80, position.getY() + 50, BULLET_RIGHT);
					else
						billBullets->createBullut(position.getX(), position.getY() + 50, BULLET_LEFT);
				}
				else
				{
					if (directionX == RIGHT)
						billBullets->createBullut(position.getX() + 60, position.getY() + 22, BULLET_RIGHT);
					else
						billBullets->createBullut(position.getX(), position.getY() + 22, BULLET_LEFT);

				}
			}

			isShooting = true;
			alastShootTime = gameTime;
			lastShootTime = gameTime;
		}



	}
	else if (type == M_JUMP)
	{
		if (position.getY() > 375 && position.getX() + gameActivity->backGround->curPosition->getX() < 4500)
			act = INWATER;
		static double lastJump;
		if (gameTime - lastJump > 12.0 / 60&&act!=INWATER)
		{
			if (directionY == DOWN)
			{
				if(position.getX()<375)
					position.setY(position.getY() + 30);
			}
			else if (isJump == false && (directionY != DOWN || act == STAND||act==INWATER))
			{
				Velocity.setY(-9);
				position.setY(position.getY() - 20);
			}
			
			lastJump = gameTime;
		}
		isJump = true;
			
	}
	else
	{
		debug.GameError("Bill message 错误。");
	}
	return 0;
}

bool Bill::isLand()
{
	for (unsigned int i = 0; i < grassArea.size(); i++)
	{
		if (myFootArea->isIntersect(*(grassArea[i])))
			return true;
	}
	if (position.getY() >= 400) return true;
	return false;
}


Bill::~Bill()
{
}