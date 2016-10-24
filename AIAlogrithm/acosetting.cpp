#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

#include "acosetting.h"
#include "cityinfo.h"
#include "config.h"
#include "methods.h"

ACOSetting::ACOSetting(QWidget *parent)
	: QDialog(parent),  ant_config_(new AntAlgConfig)
{
	ui.setupUi(this);
	connect(ui.okButton, SIGNAL(clicked()), SLOT(okClicked()));
	connect(ui.cancelButton, SIGNAL(clicked()), SLOT(cancelClicked()));
	
}

ACOSetting::~ACOSetting()
{
	delete ant_config_;
}

void ACOSetting::okClicked()
{
	if (!Methods::textToNumber(*ui.ant_text, &ant_config_->ant_cnt)||ant_config_->ant_cnt<=0)
	{
		QMessageBox::information(this, "error", "error city count!->" + ui.ant_text->text());
		return;
	}
	if (!Methods::textToNumber(*ui.times_text, &ant_config_->max_times)||ant_config_->max_times<=0)
	{
		QMessageBox::information(this, "error", "error city count!->" + ui.times_text->text());
		return;

	}
	if (!Methods::textToNumber(*ui.alpha_text, &ant_config_->alpha)||ant_config_->alpha<=0)
	{
		QMessageBox::information(this, "error", "error alpha!->" + ui.alpha_text->text());
		return;
	}
	if (!Methods::textToNumber(*ui.beta_text, &ant_config_->beta) || ant_config_->beta <= 0)
	{
		QMessageBox::information(this, "error", "error beta!->" + ui.beta_text->text());
		return;
	}
	if (!Methods::textToNumber(*ui.rou_text, &ant_config_->rou) || ant_config_->rou <= 0)
	{
		QMessageBox::information(this, "error", "error rou!->" + ui.rou_text->text());
		return;
	}
	//ant_config_->rou = 1 - ant_config_->rou;
	if (!Methods::textToNumber(*ui.pheromone_text, &ant_config_->pheromones) || ant_config_->pheromones <= 0)
	{
		QMessageBox::information(this, "error", "error pheromones!->" + ui.pheromone_text->text());
		return;
	}
	accept();
}

void ACOSetting::cancelClicked()
{
	reject();
}


const AntAlgConfig& ACOSetting::get_ant_config() const
{
	return *ant_config_;
}


//inline bool ACOSetting::textToNumber(QLineEdit &line_edit, double *rel)
//{
//	bool ok;
//	*rel = line_edit.text().toDouble(&ok);
//	return ok;
//}
