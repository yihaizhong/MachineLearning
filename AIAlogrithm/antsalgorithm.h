#ifndef ANTSALGORITHM_H
#define ANTSALGORITHM_H
#include <QVector>
#include "algorithmtsp.h"
class Ant;
struct AntAlgConfig;
/**
* @brief ACO
*/
class AntsAlgorithm:public AlgorithmTSP
{
public:
	AntsAlgorithm();
	~AntsAlgorithm();
    /**
     * @brief solve TSP
     */
	virtual void solve();
    /**
	 * @brief config the algorithm
	 * @param city_info city position
	 * @param ant_alg_config ACO parameters
	 */
	void config(const CityInfo &city_info,const AntAlgConfig &ant_alg_config);

private:
    /**
	 * @brief update the trial for all ants
	 */
    void updateTrial();
    /**
     * @brief release ants and ACO parameters for reconfiguring
     */
	void release();
    /**
     * @brief savePathToFile for test
	 * @param file_path
     */
	void savePathToFile(const QString &file_path);
	AntAlgConfig *ant_alg_config_;
	QVector<Ant*> ants_;
};

#endif // ANTSALGORITHM_H
