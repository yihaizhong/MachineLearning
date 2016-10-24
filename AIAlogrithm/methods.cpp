#include "methods.h"
#include <QTime>


int Methods::randIn(int rmin, int rmax)
{
	static int i = 2;
	QTime ct = QTime::currentTime();
	int seed = ct.hour() * 3600 + ct.minute() * 60 + ct.second()+i*i;
	qsrand(seed);
	i += qrand() % 8+5;
	return rmin + qrand() % (rmax - rmin);
}

double Methods::randIn(double rmin, double rmax)
{
	static int i = 2;
	QTime ct = QTime::currentTime();
	int seed = ct.hour() * 3600 + ct.minute() * 60 + ct.second() + i * i;
	qsrand(seed);
	i += qrand() % 8 + 5;
	return rmin + qrand() % 100000 / 100000.0* (rmax - rmin);
}
