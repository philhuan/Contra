#pragma once
#pragma execution_character_set("utf-8")

#include <graphics.h>
#include<conio.h>
#include"Application.h"
#include "main.h"
#include"Debug.h"
#include "Physical.h"
#include"HJW.h"

Application * application;
Debug debug;			//debug¹¤¾ß
int main()
{
	debug.GameLog("start.");
	application=new Application();
	application->start();
	debug.GameLog("return");
	return 0;
}




