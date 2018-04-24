#pragma once
#pragma execution_character_set("utf-8")
#include<graphics.h>
#pragma comment( lib, "MSIMG32.LIB")


//用于显示透明图片
void putbmp(double x, double y, double w, double h, IMAGE *img, UINT color = 0);//位置与长宽，最后一个参数是透明图片的透明色

//TODO:检查所有返回值有没有被delete
IMAGE** cutIMAGE(			//记得delete
	IMAGE* pDstImg,		// 保存图像的 IMAGE 对象指针
	int h,					//分为多少行
	int l,					//分为多少列
	double width,			//每一小张图片的width
	double height			//每一小张图片的height
);

//这个函数用于从文件中读取图像。
void FileToImg(
	IMAGE* pDstImg,		// 保存图像的 IMAGE 对象指针
	LPCTSTR pImgFile,		// 图片文件名
	double nWidth = 0,		// 图片的拉伸宽度
	double nHeight = 0,		// 图片的拉伸高度
	bool bResize = false	// 是否调整 IMAGE 的大小以适应图片
);

void SourceToImg(
	IMAGE* pDstImg,		// 保存图像的 IMAGE 对象指针
	LPCTSTR pResType,		// 资源类型
	LPCTSTR pResName,		// 资源名称
	double width = 0,		// 图片的拉伸宽度
	double height = 0,		// 图片的拉伸高度
	bool bResize = false	// 是否调整 IMAGE 的大小以适应图片

);

//用于在当前设备上绘制指定图像。
void showImg(
	double dstX,              // 绘制位置的 x 坐标
	double dstY,              // 绘制位置的 y 坐标
	double dstWidth,          // 绘制的宽度
	double dstHeight,         // 绘制的高度
	IMAGE *pSrcImg,        // 要绘制的 IMAGE 对象指针
	double srcX,              // 绘制内容在 IMAGE 对象中的左上角 x 坐标
	double srcY,              // 绘制内容在 IMAGE 对象中的左上角 y 坐标
	DWORD dwRop = SRCCOPY  // 三元光栅操作码（详见备注）
);

// 从当前绘图设备获取图像
void getImg(
	IMAGE* pDstImg,   // 保存图像的 IMAGE 对象指针
	double srcX,         // 要获取图像区域左上角 x 坐标
	double srcY,         // 要获取图像区域的左上角 y 坐标
	double srcWidth,     // 要获取图像区域的宽度
	double srcHeight     // 要获取图像区域的高度
);
