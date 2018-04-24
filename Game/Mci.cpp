#include "Mci.h"


int Mci::num = 0;
Mci::Mci(LPCTSTR strResType, LPCTSTR strResName,bool isWav)
{
	char tmppath[200];
	::GetTempPath(200, tmppath);
	
	if (isWav)
		sprintf_s(fileName, "%s%d.wav", tmppath, num++);
	else
		sprintf_s(fileName, "%s%d.mp3", tmppath, num++);
	sprintf_s(mcicmd, 200,"open \"%s\" alias mymusic", fileName);
	SourceToTempFile(fileName, strResType, strResName);
}

Mci::~Mci()
{
	mciSendString(("close mymusic"), NULL, 0, NULL);
	// 删除临时文件
	DeleteFile(fileName);
}

bool Mci::SourceToTempFile(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)
{
	// 创建文件
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	// 查找资源文件中、加载资源到内存、得到资源大小
	HRSRC    hRes = ::FindResource(NULL, strResName, strResType);
	if (hRes == NULL) return false;
	HGLOBAL    hMem = ::LoadResource(NULL, hRes);
	DWORD    dwSize = ::SizeofResource(NULL, hRes);

	// 写入文件
	DWORD dwWrite = 0;      // 返回写入字节
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	if (::CloseHandle(hFile) == false)
		return false;
	return true;
}

int Mci::play()
{
	DWORD e =mciSendString(mcicmd, NULL, 0, NULL);
	char a[100];
	mciGetErrorString(e, a, strlen(a));
	DWORD e1=mciSendString("play mymusic from 0", NULL, 0, NULL);
	char a1[100];
	mciGetErrorString(e1, a1, strlen(a));
	return 0;
}

int Mci::stop()
{
	mciSendString(("stop mymusic"), NULL, 0, NULL);
	return 0;
}
