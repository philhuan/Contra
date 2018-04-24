#pragma once
#pragma execution_character_set("utf-8")
#include<stdio.h>
#include<tchar.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

class Mci
{
public:
	Mci(LPCTSTR strResType, LPCTSTR strResName,bool isWav=true);
	~Mci();
	bool SourceToTempFile(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName); //将SOURCE文件写入临时文件
	int play();
	int stop();
private:
	char mcicmd[300];
	static int num;
	char fileName[200];
};

