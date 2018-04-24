#include<graphics.h>
#include <stdio.h>
#include "Debug.h"

Debug::Debug()
{
	dwnd = GetHWnd();
	if (fopen_s(&efp, "error.out", "w") != 0)
	{
		GameTip("error.out open failed.");
	}
	if (fopen_s(&lfp, "log.out", "w") != 0)
	{
		GameTip("log.out open failed.");
	}
}



int Debug::GameError(char * e)
{
	fprintf(efp, "%s\n", e);
	return 0;
}

int Debug::GameLog(char * l)
{
	fprintf(lfp, "%s\n", l);
	return 0;
}

int Debug::GameLog(double num)
{
	char *s = new char[20];
	sprintf_s(s, 20, "%f", num);
	GameLog(s);
	delete[]s;
	return 0;
	return 0;
}

int Debug::GameTip(char * t)
{
	MessageBox(dwnd, t, "tips", MB_OK );
	return 0;
}

int Debug::GameTip(double num)
{
	char *s = new char[20];
	sprintf_s(s, 20,"%f", num);
	GameTip(s);
	delete[]s;
	return 0;
}


Debug::~Debug()
{
	fclose(efp);
	fclose(lfp);
}