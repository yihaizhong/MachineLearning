#include "cityinfo.h"
#include <QString>
#include <QTime>
#include <QPointF>
#include <QFile>
#include <QTextStream>

#include "methods.h"
#include "QRect"

CityInfo::CityInfo()
{

}

CityInfo::CityInfo(const CityInfo &city_info)
{
	city_table_ = city_info.city_table_;
}

CityInfo::~CityInfo()
{

}

//void CityInfo::set_city_count(int city_count)
//{
//	if (city_count > 1)
//		city_count_ = city_count;
//	else
//		throw QString("Don't set enough cities");
//}

void CityInfo::set_city_table(const QVector<QPointF> &city_table)
{
	if (city_table.size() == 0)
		throw QString("There is no city!");
	else
		city_table_ = city_table;
}

void CityInfo::set_city_table(const QPointF *city_table,int city_count)
{
	city_table_.clear();
	city_table_.resize(city_count);
	for (int i = 0; i < city_count;++i)
	{
		city_table_.push_back(city_table[i]);
	
	}
}

inline double GetDistance(const QPointF &p1, const QPointF &p2)
{
	return sqrt((p1.x() - p2.x())*(p1.x() - p2.x()) +
		(p1.y() - p2.y())*(p1.y() - p2.y()));
}
double CityInfo::getDistance(int i, int j)const
{
	if (i<0 || i>get_city_count() - 1 || j<0 || j>get_city_count() - 1)
	{
		throw QString("the index is out range!");
	}
	else
	{
		return GetDistance(city_table_[i], city_table_[j]);
	}
}

void CityInfo::initCitiesRandomly(int city_count)
{
	if (city_count == 0)
		return;
	city_table_.resize(city_count);
	for (int i = 0; i < city_count;++i)
	{
		int x = Methods::randIn(-1000, 1000);
		int y = Methods::randIn(-1000, 1000);
		QPointF p(x, y);
		bool too_short = false;
		for (int j = 1; j < i;++j)
		{
			if (GetDistance(city_table_[j], p) < 50)
			{
				too_short = true;
				break;
			}
		}
		if (too_short)
		{
			--i;
			continue;
		}
		setCity(i,p );
	}
}

inline void CityInfo::setCity(int i, const QPointF &location)
{
	city_table_[i] = location;
}

inline int CityInfo::get_city_count() const
{
	return city_table_.size();
}

void CityInfo::saveToFile(const QString &file)
{
	QFile qfile(file);
	if (!qfile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
		throw QString("can not open or create the file->"+file);
	QTextStream stream(&qfile);
	for (int i = 0; i < city_table_.size(); i++)
	{
		stream << city_table_[i].x() << " " << city_table_[i].y() << endl;
	}
	stream.flush();
	qfile.close();
}

CityInfo& CityInfo::operator=(const CityInfo&city_info)
{
	this->city_table_ = city_info.city_table_;
	return *this;
}

QPointF CityInfo::get_city(int i) const
{
	return city_table_[i];
}

QRectF CityInfo::getBound() const
{
	double x_min = DBL_MAX, y_min = DBL_MAX, x_max = DBL_MIN, y_max = DBL_MIN;
	for (int i = 0; i < city_table_.size(); ++i)
	{
		const QPointF &p = city_table_[i];
		if (p.x() < x_min)
			x_min = p.x();
		if (p.y() < y_min)
			y_min = p.y();
		if (p.x() > x_max)
			x_max = p.x();
		if (p.y() > y_max)
			y_max = p.y();
	}
	return QRectF(x_min, y_min, x_max - x_min, y_max - y_min);
}
