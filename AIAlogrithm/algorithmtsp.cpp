#include "algorithmtsp.h"
#include "cityinfo.h"


AlgorithmTSP::AlgorithmTSP()
	:city_info_(nullptr)
{

}

AlgorithmTSP::~AlgorithmTSP()
{
	if (city_info_)
		delete city_info_;
}

void AlgorithmTSP::set_city_info(const CityInfo &city_info)
{
	if (city_info_)
		delete city_info_;
	city_info_ = new CityInfo(city_info);
}

const QVector<double> & AlgorithmTSP::get_all_length()
{
	return all_length_;
}

double AlgorithmTSP::get_min_length() const
{
	return min_length_;
}

const QVector<int> AlgorithmTSP::get_best_path() const
{
	return best_path_;
}
