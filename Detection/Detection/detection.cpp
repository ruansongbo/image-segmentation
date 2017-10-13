#include "detection.h"
#include "camera.h"
#include "connection.h"
#include "history.h"
#include "parameter.h"
#include "system.h"
#include "template.h"

Detection::Detection(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Detection::~Detection()
{

}

void Detection::paintEvent(QPaintEvent*)
{
	paint = new QPainter;
	QImage OK;
	QImage NG;
	paint->begin(this);
	OK.load("./Resources/OK.png"); //"C:/Users/bb/Desktop/test.jpg");
	NG.load("./Resources/NG.png");
	//paint->drawImage(QPoint(770, 140), image);
	//paint->setPen(QPen(Qt::blue, 4, Qt::DashLine));//设置画笔形式 
	//paint->setBrush(QBrush(Qt::red, Qt::SolidPattern));//设置画刷形式 
	//paint->drawRect(660, 20, 790, 130);
	//paint->drawPixmap(770, 140, 60, 60, OK);
	QImage OKImg = OK.scaled(ui.resultlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	QImage NGImg = NG.scaled(ui.resultlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	ui.masterlabel->setPixmap(QPixmap::fromImage(NGImg));
	ui.masterlabel->show();
	ui.Rsenlabel->setPixmap(QPixmap::fromImage(NGImg));
	ui.Rsenlabel->show();
	ui.Lsenlabel->setPixmap(QPixmap::fromImage(OKImg));
	ui.Lsenlabel->show();
	ui.resultlabel->setPixmap(QPixmap::fromImage(OKImg));
	ui.resultlabel->show();
	paint->end();
}
void Detection::camera_set()
{
	Camera CameraWin(this);
	if (CameraWin.exec())
	{

	}
}
void Detection::template_set()
{
	Template TemplateWin(this);
	if (TemplateWin.exec())
	{

	}
}
void Detection::paramter_set()
{
	Parameter ParameterWin(this);
	if (ParameterWin.exec())
	{

	}
}
void Detection::connection_set()
{
	Connection ConnectionWin(this);
	if (ConnectionWin.exec())
	{

	}
}
void Detection::system_set()
{
	System SystemWin(this);
	if (SystemWin.exec())
	{

	}
}
void Detection::history_display()
{
	History HistoryWin(this);
	if (HistoryWin.exec())
	{

	}
}