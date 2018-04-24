#include "SimpleImageView.h"
#include"HJW.h"

SimpleImageView::SimpleImageView():
	PartView(0,0,40,40),Area(0,0,40,40)
{

	onCreate();
}

SimpleImageView::SimpleImageView(double x, double y, double width, double height)
	:PartView(x,y,width,height),Area(x, y, width, height)
{
}

SimpleImageView::~SimpleImageView()
{
}

int SimpleImageView::onCreate()
{
	return 0;
}

int SimpleImageView::addIMAGE(IMAGE img)
{
	image = img;
	return 0;
}

View * SimpleImageView::draw()
{
	
	return draw(getPositionX(), getPositionY(), getWidth(), getHeight());
}

View * SimpleImageView::draw(double x, double y)
{
	return draw(x,y, getWidth(), getHeight());
}

View * SimpleImageView::draw(VecPosition position)
{
	return draw(position.getX(),position.getY(), getWidth(), getHeight());
}

View * SimpleImageView::draw(double x, double y, double width, double height)
{
	showImg(x, y, width, height,&image,0,0);
	return this;
}
