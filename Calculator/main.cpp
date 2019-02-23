#include "calculatorFrame.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	calculatorFrame w;
	w.show();
	return a.exec();
}
