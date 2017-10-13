#ifndef TEST_H
#define TEST_H

#include <QtWidgets/QMainWindow>
#include "ui_test.h"
#include "qpixmap.h"
#include "qpainter.h"
#include "qimage.h"

class test : public QMainWindow
{
	Q_OBJECT

public:
	test(QWidget *parent = 0);
	~test();
	void paintEvent(QPaintEvent*);
	QPainter *paint;
	QPixmap image1;

private:
	Ui::testClass ui;
};

#endif // TEST_H
