#include "eachpath.h"
#include <QPainter>
#include <algorithm>
#include "QMessageBox"

EachPath::EachPath(const QVector<double> &each_path,QWidget *parent)
	: QDialog(parent), each_path_(each_path), show_(false)
{
	ui.setupUi(this);
	drawImage();
}

EachPath::~EachPath()
{
	delete img_;
}

void EachPath::paintEvent(QPaintEvent *pevent)
{
	
	if (each_path_.size() == 0)
		return;
	if (!show_)
		return;
	QPainter painter;
	painter.begin(this);	
	painter.drawImage(0, 0, *img_);
	painter.end();
}

int EachPath::exec()
{
	show_ = true;
	update();
	return QDialog::exec();
}

void EachPath::drawImage()
{
	img_ = new QImage(1280, 800, QImage::Format_RGB888);
	img_->fill(QColor::fromRgb(255, 255, 255));
	QPainter painter;
	painter.setRenderHint(QPainter::HighQualityAntialiasing);
	painter.begin(img_);
	double max_l = each_path_[0];
	double min_l = each_path_[each_path_.size() - 1];
	int times = each_path_.size();
	int height = max_l - min_l;
	double kx = 1180.0 / times, ky = 600.0 / (height);
	double px = 50, py = 650;
	painter.drawLine(50, 700, 1260, 700);
	painter.drawLine(50, 700, 50, 20);
	painter.drawLine(1260, 700, 1250, 690);
	painter.drawLine(1260, 700, 1250, 710);
	painter.drawLine(50, 20, 40, 30);
	painter.drawLine(50, 20, 60, 30);
	painter.drawText(50, 720, "(0," + QString::number(min_l - 100 * ky) + ")");
	painter.drawText(600, 720, "min_length=" + QString::number(min_l));
	painter.drawText(20, 15, "path length");
	painter.drawText(1240, 720, "times");
	QRect r = painter.window();
	QVector<QPointF> points(times);
	for (int i = 0; i < times; ++i)
	{
		points[i].setX(px + i*kx);
		points[i].setY(py - (each_path_[i] - min_l)*ky);
	}
	QPen pen(Qt::blue);
	pen.setWidth(2);
	painter.setPen(pen);
	painter.drawPolyline(points.data(), times);
	painter.end();
}

