#pragma once
#pragma execution_character_set("utf-8")

#include <graphics.h>
#include <conio.h>
#include "HJW.h"
#include "main.h"


int tranW(double beforeW);
int tranH(double beforeH);

void putbmp(double x, double y, double w, double h, IMAGE *img, UINT color)
{
	// 获取绘图窗口和 IMAGE 对象的句柄，TransparentBlt 函数需要用
	HDC dstDC = GetImageHDC();
	HDC srcDC = GetImageHDC(img);
	// 使用 Windows GDI 函数实现透明位图
	TransparentBlt(dstDC, tranW(x), tranH(y), tranW(w), tranH(h), srcDC, 0, 0, tranW(w), tranH(h), color); // 最后一个参数是表示透明色为白色					
	//FlushBatchDraw();
}

IMAGE ** cutIMAGE(IMAGE * pDstImg, int h, int l,double width,double height)
{
	IMAGE **img= new IMAGE*[h];
	for (int i = 0; i < h; i++)
		img[i] = new IMAGE[l];
	SetWorkingImage(pDstImg);
	for(int i=0;i<h;i++)
		for (int j = 0; j < l; j++)
		{
			getImg(&img[i][j], j*width, i * height, width, height);
		}
	SetWorkingImage();

	return img;
}

void FileToImg(IMAGE * pDstImg, LPCTSTR pImgFile, double nWidth, double nHeight, bool bResize)
{
	loadimage(pDstImg, pImgFile, tranW(nWidth), tranH(nHeight), bResize);
}

void SourceToImg(IMAGE * pDstImg, LPCTSTR pResType, LPCTSTR pResName, double width, double height, bool bResize)
{
	loadimage(pDstImg, pResType, pResName, tranW(width), tranH(height), bResize);
}



void showImg(double dstX, double dstY, double dstWidth, double dstHeight, IMAGE * pSrcImg, double srcX, double srcY, DWORD dwRop)
{
	putimage(tranW(dstX), tranH(dstY), tranW(dstWidth), tranH(dstHeight), pSrcImg, tranW(srcX), tranH(srcY), dwRop);
}

void getImg(IMAGE * pDstImg, double srcX, double srcY, double srcWidth, double srcHeight)
{
	getimage(pDstImg, tranW(srcX), tranH(srcY), tranW(srcWidth), tranH(srcHeight));
}

int tranW(double beforeW)
{
	return (int)(beforeW*srcWidth / 640);
}

int tranH(double beforeH)
{
	return (int)(beforeH*srcHeight / 480);
}