#ifndef ALGORITHMTSP_H
#define ALGORITHMTSP_H
#include <QVector>
class CityInfo;

class AlgorithmTSP
{
public:
	AlgorithmTSP();
	virtual ~AlgorithmTSP();
    /**
	 * @brief get shortest path length in each time
	 * @return a vector of length
	 */
	const QVector<double> &get_all_length();
    /**
     * @brief get minium length after all steps
     * @return
     */
	double get_min_length()const;
	/**
	 * @brief get best path
	 * @return a vector of city number in order
	 */
	const QVector<int> get_best_path()const;
    /**
     * @brief set city position
     */
	virtual void set_city_info(const CityInfo &);
	/**
	 * @brief solve the TSP.It can be inherited to use different alhgorithm.
	 */
	virtual void solve() = 0;
protected:
	CityInfo *city_info_;
	QVector<double> all_length_;
	QVector<int> best_path_;
	double min_length_;
};



#endif // ALGORITHMTSP_H
