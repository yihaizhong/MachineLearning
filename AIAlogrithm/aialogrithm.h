#ifndef AIALOGRITHM_H
#define AIALOGRITHM_H

#include <QtWidgets/QMainWindow>
#include "ui_aialogrithm.h"
class CitySetting;
class ACOSetting;
class AlgorithmTSP;

class AIAlogrithm : public QMainWindow
{
	Q_OBJECT

public:
	AIAlogrithm(QWidget *parent = 0);
	~AIAlogrithm();
	enum EState
	{
		INIT_CITY,
		RESULT_CITY,
		NONE
	};
protected:
	void paintEvent(QPaintEvent *);
private slots:
	void tspACO();
	void tspCity();
private:
	void initCities();
	void paintCities(QPainter &);
	void showPath();
	void solveAndShow();
	Ui::AIAlogrithmClass ui;
	ACOSetting *aco_setting_;
	CitySetting *city_setting_;
	AlgorithmTSP *tsp_alg_;
	EState state_;
};

#endif // AIALOGRITHM_H
