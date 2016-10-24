#include "antsalgorithm.h"
#include "config.h"
#include "ant.h"
#include "cityinfo.h"
#include <QString>
#include <QFile>
#include <QTextStream>

AntsAlgorithm::AntsAlgorithm()
	:ant_alg_config_(nullptr)
{

}


AntsAlgorithm::~AntsAlgorithm()
{
	release();
	Ant::releaseTrial();
}

void AntsAlgorithm::solve()
{

	//在迭代次数内进行循环
	for (int i = 0; i < ant_alg_config_->max_times; i++)
	{
		//每只蚂蚁搜索一遍
		for (int j = 0; j < ant_alg_config_->ant_cnt; j++)
		{
			ants_[j]->search();
		}

		//保存最佳结果
		for (int j = 0; j < ant_alg_config_->ant_cnt; j++)
		{
	
			if (ants_[j]->get_path_leangth() < min_length_)
			{
				min_length_ = ants_[j]->get_path_leangth();
				ants_[j]->setPathToVector(best_path_);
			}
		}
		all_length_.push_back(min_length_);
		//更新环境信息素
		updateTrial();

	}
	//savePathToFile("path.txt");
	//city_info_->saveToFile("city.txt");
}


void AntsAlgorithm::config(const CityInfo &city_info, const AntAlgConfig &ant_alg_config)
{
	//clear before reconfigure
	all_length_.clear();
	if (ants_.size() > 0)
	{
		release();
	}

	//initialize
	ants_.resize(ant_alg_config.ant_cnt);
	best_path_.resize(city_info.get_city_count());
	ant_alg_config_ = new AntAlgConfig(ant_alg_config);
	set_city_info(city_info);
	Ant::initTrial(city_info_->get_city_count());

	for (int i = 0; i < ant_alg_config.ant_cnt;++i)
	{
		ants_[i] = new Ant(*city_info_, *ant_alg_config_);
	}
	for (int i = 0; i < city_info_->get_city_count();++i)
	{
		best_path_[i] = -1;
	}
	min_length_=DBL_MAX;
}


void AntsAlgorithm::updateTrial()
{
	//临时数组，保存各只蚂蚁在两两城市间新留下的信息素
	int city_cnt = city_info_->get_city_count();
	double **temp = new double *[city_cnt];
	for (int i = 0; i < city_cnt;++i)
	{
		temp[i] = new double[city_cnt];
		memset(temp[i], 0, sizeof(double)*city_cnt);
	}
	 //先全部设置为0

	//计算新增加的信息素,保存到临时数组里
	int m = 0;
	int n = 0;
	for (int i = 0; i < ant_alg_config_->ant_cnt; i++) //计算每只蚂蚁留下的信息素
	{
		for (int j = 1; j < city_cnt; j++)
		{
			m = ants_[i]->getPath(j);
			n = ants_[i]->getPath(j - 1);
			temp[n][m] = temp[n][m] + ant_alg_config_->pheromones / ants_[i]->get_path_leangth();
			temp[m][n] = temp[n][m];
		}

		//最后城市和开始城市之间的信息素
		n = ants_[i]->getPath(0);
		temp[n][m] = temp[n][m] + ant_alg_config_->pheromones / ants_[i]->get_path_leangth();
		temp[m][n] = temp[n][m];

	}

	//==================================================================
	//更新环境信息素
	for (int i = 0; i < city_cnt; i++)
	{
		for (int j = 0; j < city_cnt; j++)
		{
			double tmp = Ant::getTrial(i, j) * ant_alg_config_->rou + temp[i][j]; //最新的环境信息素 = 留存的信息素 + 新留下的信息素
			Ant::setTrial(i, j, tmp);
		}
	}
	Ant::output();
	for (int i = 0; i < city_cnt; ++i)
	{
		delete []temp[i];
	}
	delete[]temp;
}

void AntsAlgorithm::release()
{
	for (int i = 0; i < ants_.size(); ++i)
	{
		delete ants_[i];
	}
	if (ant_alg_config_)
		delete ant_alg_config_;
}

void AntsAlgorithm::savePathToFile(const QString &file_path)
{
	QFile file(file_path);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
		throw QString("can not open or create the file->" + file_path);
	QTextStream stream(&file);
	for (int i = 0; i < best_path_.size();++i)
	{
		stream << best_path_[i] << endl;
	}
	stream.flush();
	file.close();
}


