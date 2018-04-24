#pragma once
#pragma execution_character_set("utf-8")
#include"Physical.h"

class Nfc :public Physical
{
public:
	Nfc();
	~Nfc();
	int run();
protected:
	double life;

};
