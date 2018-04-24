#include "KeyListenner.h"
#include <graphics.h>
#include <conio.h>
#include<stdio.h>
KeyListenner::KeyListenner()
{
}

KeyListenner::~KeyListenner()
{
}

int KeyListenner::ListenKey()
{
	return 0;
}



bool KeyListenner::isClicked(int in)
{
	if (::GetAsyncKeyState(in))
		return true;
	return false;
}




