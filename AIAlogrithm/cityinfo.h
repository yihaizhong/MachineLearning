#ifndef CITYINFO_H
#define CITYINFO_H
#include <QVector>
class QPointF;
class QRectF;
class CityInfo
{
public:
	CityInfo();
	CityInfo(const CityInfo&);
	CityInfo& operator=(const CityInfo&);
	virtual ~CityInfo();
    /**
     * @brief get the number of cities
     * @return number of cities
     */
	int get_city_count()const;
    /**
     * @brief get city position in No.i
     * @param the number of city
     * @return the position
     */
	QPointF get_city(int i)const;
    /**
     * @brief get the bound of all cities
     * @return a rectangle bound
     */
	QRectF getBound()const;
    /**
     * @brief set_city_table
     * @param city_table
     */
	virtual void set_city_table(const QVector<QPointF> &city_table);
    /**
     * @brief set_city_table
     * @param city_table
     * @param city_count
     */
	virtual void set_city_table(const QPointF *city_table,int city_count);
    /**
     * @brief init cities randomly
     * @param city_count the number of cities
     */
	virtual void initCitiesRandomly(int city_count);
    /**
     * @brief getDistance
     * @param i the first city number
     * @param j the second city number
     * @return the distance between No.i city and No.j city
     */
	virtual double getDistance(int i, int j)const;
    /**
     * @brief saveToFile for test
     * @param file
     */
	virtual void saveToFile(const QString &file);
protected:
    /**
     * @brief set No.i city,for internal use
     * @param i
     * @param location
     */
	virtual void setCity(int i, const QPointF &location);
    QVector<QPointF> city_table_;//save the position of cities;
};

#endif // CITYINFO_H
