#ifndef ANT_H
#define ANT_H
#include <QVector>
class QString;
class CityInfo;
struct AntConfig;
class Ant
{
public:
	Ant(CityInfo &city_info,AntConfig &ant_config);
	Ant(const Ant&)=delete;
	Ant &operator=(const Ant &)=delete;
	~Ant();
public:
    /**
     * @brief init trial by a const value
     * @param city_count
     * @param init_val
     */
	static void initTrial(int city_count,double init_val=1.0);
    /**
     * @brief get the trial between No.i and No.j
     * @param i first city
     * @param j second city
     * @return the trial
     */
	static double getTrial(int i, int j);
    /**
     * @brief set the trial between No.i and No.j
     * @param i first city
     * @param j second city
     * @param trial value to set
     */
	static void setTrial(int i, int j,double trial);
    /**
     * @brief release
     */
	static void releaseTrial();
    /**
     * @brief output the trial for test
     */
	static void output();
    /**
     * @brief search the path
     */
    void search();
    /**
     * @brief get_path_leangth
     * @return
     */
	double get_path_leangth()const;
    /**
     * @brief get the i-th path
     * @param i
     * @return
     */
	int getPath(int i)const;
    /**
     * @brief set path to vector
     * @param path
     */
	void setPathToVector(QVector<int> &path)const;
    /**
     * @brief save path to file for test
     * @param file
     */
	void savePathToFile(const QString &file);
private:
    /**
     * @brief choose next city by using roulette selection method
     * @return
     */
    int chooseNextCity();
    /**
     * @brief init the status
     */
    void init();
    /**
     * @brief move to next city
     */
    void move();
    /**
     * @brief calculate the path length
     */
    void calPathLength();
    CityInfo &city_info_;//city info
    AntConfig &ant_config_;//ACO parameter
    double path_length_; //path length
    int cur_city_no_; //current city number
    int moved_city_count_; //number visited cities
    QVector<int> path_; //the sort list of visited cities
    QVector<bool> allowed_city; //if the city has been visited
    static double **trial_;//trial for all the ants
    static int city_count_;//number of cities
};

#endif // ANT_H
