#include "detection.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	detection w;
	w.show();
	return a.exec();
}
