#include "aialogrithm.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>
#include "tsp.h"
#include "config.h"
#include "antsalgorithm.h"
#include "cityinfo.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//AntAlgConfig aac;
	//aac.alpha = 1;
	//aac.beta = 2;
	//aac.rou = 0.8;
	//aac.ant_cnt = 20;
	//aac.max_times = 1000;
	//aac.pheromones = 1;
	//CityInfo ci;
	//QVector<QPointF> points;
	////double C[][2] = {
	////	{ 2, 99 }, { 4, 50 }, { 7, 64 }, { 13, 40 }, { 18, 54 }, { 18, 40 }, { 22, 60 }, { 24, 42 }, { 25, 62 }, { 25, 38 },
	////	{ 37, 84 }, { 41, 94 }, { 41, 26 }, { 44, 35 }, { 45, 21 }, { 54, 67 }, { 54, 62 }, { 58, 35 }, { 58, 69 }, { 62, 32 },
	////	{ 64, 60 }, { 68, 58 }, { 71, 44 }, { 71, 71 }, { 74, 78 }, { 82, 7 }, { 83, 46 }, { 83, 69 }, { 87, 76 }, { 91, 38 } };
	//double C[][2] = {
	//	{ 5, 64 }, { 5, 25 }, { 5, 6 }, { 7, 38 }, { 8, 52 }, { 10, 17 },
	//	{ 12, 42 }, { 13, 13 }, { 16, 57 }, { 17, 33 }, { 17, 63 },
	//	{ 20, 26 }, { 21, 47 }, { 21, 10 }, { 25, 32 }, { 25, 55 },
	//	{ 27, 68 }, { 27, 23 }, { 30, 48 }, { 30, 15 }, { 31, 62 },
	//	{ 31, 32 }, { 32, 22 }, { 32, 39 }, { 36, 16 }, { 37, 69 },
	//	{ 37, 52 }, { 38, 46 }, { 39, 10 }, { 40, 30 }, { 42, 57 },
	//	{ 42, 41 }, { 43, 67 }, { 45, 35 }, { 46, 10 }, { 48, 28 },
	//	{ 49, 49 }, { 51, 21 }, { 52, 33 }, { 52, 41 }, { 52, 64 },
	//	{ 56, 37 }, { 57, 58 }, { 58, 27 }, { 58, 48 }, { 59, 15 },
	//	{ 61, 33 }, { 62, 42 }, { 62, 63 }, { 63, 69 } };
	//for (int i = 0; i < 50; ++i)
	//{
	//	points.push_back(QPointF(C[i][0], C[i][1]));
	//}
	////ci.initCitiesRandomly(10);
	//ci.set_city_table(points);
	//AntsAlgorithm aa;
	//aa.config(ci, aac);
	//aa.solve();
	//double min_l = aa.get_min_length();
	////int cnt = 100;
	////while (cnt--)
	////{
	////	aa.config(ci, aac);
	////	aa.solve();
	////	if (aa.get_min_length()<min_l)
	////	{
	////		min_l = aa.get_min_length();
	////	}
	////}
	//QMessageBox::information(nullptr, " ", QString::number(min_l));
	AIAlogrithm w;
	w.show();
	return a.exec();
}
