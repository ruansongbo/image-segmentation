#include "test.h"

test::test(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

test::~test()
{

}
void test::paintEvent(QPaintEvent*)
{
	paint = new QPainter;
	QImage image;
	paint->begin(this);
	image1.load("C:/Users/bb/Desktop/test.jpg");
	image.load("C:/Users/bb/Desktop/11.PNG");
	paint->drawImage(QPoint(770, 140), image);
	paint->setPen(QPen(Qt::blue, 4, Qt::DashLine));//设置画笔形式 
	paint->setBrush(QBrush(Qt::red, Qt::SolidPattern));//设置画刷形式 
	paint->drawRect(560, 20, 160, 130);
	QImage resultImg = image.scaled(ui.label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	ui.label->setPixmap(QPixmap::fromImage(resultImg));
	ui.label->show();
	paint->drawPixmap(0, 0, 60, 60, image1);
	paint->end();
}