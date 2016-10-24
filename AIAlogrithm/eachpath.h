#ifndef EACHPATH_H
#define EACHPATH_H

#include <QDialog>
#include <QVector>
#include "ui_eachpath.h"

class EachPath : public QDialog
{
	Q_OBJECT

public:
	EachPath(const QVector<double> &each_path,QWidget *parent = 0);
	~EachPath();
	int exec();
	void paintEvent(QPaintEvent *);
	void drawImage();
private:
	Ui::EachPath ui;
	const QVector<double> &each_path_;
	QImage *img_;
	bool show_;
};

#endif // EACHPATH_H
