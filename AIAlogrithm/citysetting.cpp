#include "citysetting.h"
#include "QMessageBox"
#include "QFile"
#include "QFileDialog"
#include "QTextStream"
#include "cityinfo.h"
#include "methods.h"

CitySetting::CitySetting(QWidget *parent)
	: QDialog(parent),city_info_(new CityInfo)
{
	ui.setupUi(this);
	
	connect(ui.data_source, SIGNAL(currentIndexChanged(int)), SLOT(dataSourceChanged(int)));
	connect(ui.okButton, SIGNAL(clicked()), SLOT(okClicked()));
	connect(ui.cancelButton, SIGNAL(clicked()), SLOT(cancelClicked()));
}

CitySetting::~CitySetting()
{
	delete city_info_;
}

void CitySetting::dataSourceChanged(int index)
{
	if (index == 1)
	{
		QString &file_name = QFileDialog::getOpenFileName(this, "open city information data...");
		if (file_name.isEmpty())
		{
			ui.data_source->setCurrentIndex(0);
			return;
		}
		QFile file(file_name);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QMessageBox::information(this, "error", "can not open the file->" + file_name);
			ui.data_source->setCurrentIndex(0);
			return;
		}

		QTextStream stream(&file);
		QString line;
		QVector<QPointF> points;
		while (!stream.atEnd())
		{
			line = stream.readLine();
			if (line.isEmpty())
				continue;
			line = line.replace("\t", " ").trimmed();
			QStringList ss = line.split(QRegExp(" +|,"));
			if (ss.size() < 2)
			{
				QMessageBox::information(this, "error", "bad format->" + line);
				ui.data_source->setCurrentIndex(0);
				return;
			}
			bool ok[2];
			double x = ss[0].toDouble(&ok[0]);
			double y = ss[1].toDouble(&ok[1]);
			if (!ok[0] || !ok[1])
			{
				QMessageBox::information(this, "error", "bad format->" + line);
				ui.data_source->setCurrentIndex(0);
				return;
			}
			points.push_back(QPointF(x, y));
		}
		file.close();
		city_info_->set_city_table(points);
		ui.city_text->setText(QString::number(points.size()));
		ui.city_text->setReadOnly(true);
	}
	else
	{
		ui.city_text->setReadOnly(false);
	}
}

void CitySetting::okClicked()
{
	int city_cnt;
	if (!Methods::textToNumber(*ui.city_text, &city_cnt)||city_cnt<0)
	{
		QMessageBox::information(this, "error", "error city count!->" + ui.city_text->text());
		return;
	}
	if (ui.data_source->currentIndex() == 0)
	{
		city_info_->initCitiesRandomly(city_cnt);
	}
	accept();
}



void CitySetting::cancelClicked()
{
	reject();
}

const CityInfo & CitySetting::get_city_info() const
{
	return *city_info_;
}
