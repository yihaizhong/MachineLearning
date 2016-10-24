#include "aialogrithm.h"
#include <QMessageBox>
#include <QGraphicsScene>
#include <QPainter>
#include "antsalgorithm.h"
#include "acosetting.h"
#include "citysetting.h"
#include "cityinfo.h"
#include "eachpath.h"


AIAlogrithm::AIAlogrithm(QWidget *parent)
	: QMainWindow(parent),
	city_setting_(new CitySetting(this)),
	aco_setting_(new ACOSetting(this)),
	tsp_alg_(nullptr),
	state_(NONE)
{
	ui.setupUi(this);
	connect(ui.actionCity_Positions_Setting, SIGNAL(triggered()), SLOT(tspCity()));
	connect(ui.actionAnt_Colony_Optimization, SIGNAL(triggered()), SLOT(tspACO()));

}

AIAlogrithm::~AIAlogrithm()
{
	if (tsp_alg_)
		delete tsp_alg_;
}

void AIAlogrithm::tspACO()
{
	if (QDialog::Accepted == aco_setting_->exec())
	{
		if (tsp_alg_)
			delete tsp_alg_;
		const AntAlgConfig &aac = aco_setting_->get_ant_config();
		AntsAlgorithm *aa = new AntsAlgorithm;
		aa->config(city_setting_->get_city_info(), aac);

		tsp_alg_ = aa;
		solveAndShow();
	}
}

void AIAlogrithm::tspCity()
{
	if (QDialog::Accepted == city_setting_->exec())
	{
		ui.actionAnt_Colony_Optimization->setEnabled(true);
		state_ = INIT_CITY;
		update();
	}
}

void AIAlogrithm::initCities()
{
	QPainter painter;
	painter.begin(this);
	paintCities(painter);
	painter.end();
}

void AIAlogrithm::paintEvent(QPaintEvent *)
{
	switch (state_)
	{
	case AIAlogrithm::INIT_CITY:
		initCities();
		break;
	case AIAlogrithm::RESULT_CITY:
		showPath();
		break;
	case AIAlogrithm::NONE:
		break;
	default:
		break;
	}
	
}

void AIAlogrithm::solveAndShow()
{
	tsp_alg_->solve();
	const QVector<double> all_length = tsp_alg_->get_all_length();

	state_ = RESULT_CITY;
	update();
	EachPath ep(tsp_alg_->get_all_length());
	ep.exec();
}

void AIAlogrithm::showPath()
{
	const CityInfo &ci = city_setting_->get_city_info();
	QVector<int> best_path = tsp_alg_->get_best_path();

	QPainter painter;
	painter.begin(this);
	QRectF bound = ci.getBound();
	double width = bound.width(), height = bound.height();
	QRect wd = painter.window();
	double px = wd.x() + 50, py = wd.y() + wd.height() - 50;
	double kx = (wd.width() - 100) / width, ky = (wd.height() - 100) / height;
	paintCities(painter);
	QVector<QPointF> points;
	for (int i = 0; i < best_path.size();++i)
	{
		const QPointF &p = ci.get_city(best_path[i]);
		points.push_back(QPointF(px + kx*(p.x() - bound.x()), py - ky*(p.y() - bound.y())));
	}
	QPen pen(QColor::fromRgb(0,0,255));
	pen.setWidth(2);
	painter.setPen(pen);
	painter.drawPolygon(points.data(), points.size());
	painter.end();
}

void AIAlogrithm::paintCities(QPainter &painter)
{
	const CityInfo& ci = city_setting_->get_city_info();
	//trans

	QRectF bound = ci.getBound();
	double width = bound.width(), height = bound.height();

	QRect wd = painter.window();
	double px = wd.x() + 50, py = wd.y()+wd.height() - 50;
	double kx = (wd.width() - 100) / width, ky = (wd.height() - 100) / height;

	QPen pen(Qt::red);
	pen.setWidth(10);
	painter.setPen(pen);
	for (int i = 0; i < ci.get_city_count(); ++i)
	{
		const QPointF &p = ci.get_city(i);
		painter.drawPoint(px + kx*(p.x()-bound.x()), py - ky*(p.y()-bound.y()));
	}
}


