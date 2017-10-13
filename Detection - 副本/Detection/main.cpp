#include "detection.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Detection w;
	w.show();
	return a.exec();
}
