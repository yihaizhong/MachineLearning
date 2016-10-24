#ifndef TSP_H
#define TSP_H
class CityInfo;
class AlgorithmTSP;

class TSP
{
public:
	TSP(CityInfo &city_info,AlgorithmTSP &algorithm);
	void set_city_info(CityInfo &city_info);
	void set_algorithm(AlgorithmTSP &algorithm);
	void solve();
	void show();
	~TSP();

private:
	CityInfo &city_info_;
	AlgorithmTSP &algorithm_;
};

#endif // TSP_H
