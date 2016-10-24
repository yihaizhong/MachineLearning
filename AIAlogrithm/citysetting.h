#ifndef CITYSETTING_H
#define CITYSETTING_H

#include <QDialog>
#include "ui_citysetting.h"
class CityInfo;

class CitySetting : public QDialog
{
	Q_OBJECT

public:
	CitySetting(QWidget *parent = 0);
	~CitySetting();
	const CityInfo &get_city_info()const;
private slots:
	void dataSourceChanged(int index);
	void okClicked();
	void cancelClicked();
private:
	Ui::CitySetting ui;
	CityInfo *city_info_;
};

#endif // CITYSETTING_H
