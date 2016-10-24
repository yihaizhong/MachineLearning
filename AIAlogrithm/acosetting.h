#ifndef ACOSETTING_H
#define ACOSETTING_H

#include <QDialog>
#include "ui_acosetting.h"
class CityInfo;
class AntAlgConfig;
class ACOSetting : public QDialog
{
	Q_OBJECT

public:
	ACOSetting(QWidget *parent = 0);
	~ACOSetting();
	const AntAlgConfig& get_ant_config()const;
private slots:
	void okClicked();
	void cancelClicked();
private:
	Ui::ACOSetting ui;
	AntAlgConfig *ant_config_;
};



#endif // ACOSETTING_H
