#ifndef CONFIG_H
#define CONFIG_H

struct AntConfig
{
	double alpha;
	double beta;
	
};
struct AntAlgConfig :public AntConfig
{
	double rou;
	double pheromones;
	int max_times;
	int ant_cnt;
};

#endif // CONFIG_H
