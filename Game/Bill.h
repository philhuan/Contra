#pragma once
#pragma execution_character_set("utf-8")
#include"Nfc.h"
#include"PartView.h"
#include"Bullets.h"
enum Bill_act {
	STAND,
	WALK,
	INWATER
};

enum JumpAct {
	j_UP,
	j_DOWN
};
enum DirectionX {
	RIGHT,
	LEFT,
	X_NULL
};

enum DirectionY {
	UP,
	DOWN,
	Y_NULL
};

class Bill : public View, public Physical
{
public:
	static int TX;
	static int TY;
	static int M_SHOOT;
	static int M_JUMP;
	Bill();
	~Bill();
	View* draw();
	void physical();
	int message(int type, int value);
	bool isLand();
private:
	int onCreate();
	bool isTouchLand();				//判断游泳的时候有没有到岸
	Bill_act act;					//现在的动作
	DirectionX directionX;
	DirectionY directionY;
	JumpAct jumpAct;
	bool isShooting;				//现在是否在按射击
	bool isJump;
	double lastShootTime;
	bool isMoving;					//是否在移动
	bool isDive;					//是否在潜水
	RePlayView *standRight;			//面朝右边站起（不开枪）
	RePlayView*standLeft;			//面朝左边站起(不开枪)
	RePlayView*standUpRight;		//面朝右举枪（不开枪）
	RePlayView*standUpLeft;			//面朝左举枪（不开枪）
	RePlayView*standShootRight;		//面朝右边站起（开枪）
	RePlayView*standShootLeft;		//面朝左边站起（开枪）
	RePlayView*walkRight;			//面朝右边跑（不开枪）
	RePlayView*walkLeft;			//面朝左边跑（不开枪）
	RePlayView*walkShootRight;			//面朝右边跑（开枪）
	RePlayView*walkShootLeft;			//面朝左边跑（开枪）
	RePlayView*walkShootRightUp;	//面朝右边跑（向右上方开枪）
	RePlayView*walkShootLeftUp;		//面朝左边跑（向左上方开枪）
	RePlayView*walkShootRightDown;	//面朝左边跑（向右下方开枪）
	RePlayView*walkShootLeftDown;	//面朝左边跑（向左下方开枪）
	RePlayView*getDownRight;		//趴下（右边）
	RePlayView*getDownLeft;			//趴下（左边）
	RePlayView*shootUpRight;		//向上开枪（右边）
	RePlayView*shootUpLeft;			//向上开枪（左边）
	RePlayView*jumpRight;			//向右跳
	RePlayView*jumpLeft;			//向左跳
	RePlayView*inWaterRight;		//在水里（右）
	RePlayView*inWaterLeft;			//在水里（左）
	RePlayView*inWaterShootUp_right;//在水里开枪（向上）
	RePlayView*inWaterShootUp_left;	//在水里开枪（向上）	
	RePlayView*inWaterShootUpRight;	//在水里开枪（向右上）
	RePlayView*inWaterShootUpLeft;	//在水里开枪（向左上）
	RePlayView*inWaterShootRight;	//在水里（右）（开枪）
	RePlayView*inWaterShootLeft;	//在水里（右）（不开枪）
	RePlayView*dive;				//潜水
	std::vector<VecPosition> grassVecList;		//草列表
	std::vector<VecPosition> waterVecList;		//水列表
	std::vector<Area*> grassArea;
	Area *myFootArea;
	Area *myArea;
	Bullets *billBullets;
};

