#include "ant.h"
#include "cityinfo.h"
#include "methods.h"
#include "config.h"
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QString>


Ant::Ant(CityInfo &city_info, AntConfig &ant_config) :
city_info_(city_info), 
ant_config_(ant_config),
path_length_(0.0),
moved_city_count_(0),
path_(city_info.get_city_count()),
allowed_city(city_info.get_city_count())
{

}



Ant::~Ant()
{
}

void Ant::init()
{
	for (int i = 0; i < city_info_.get_city_count(); ++i)
	{
		path_[i] = -1;
		allowed_city[i] = true;
	}

	//随机选择一个出发城市
	cur_city_no_ = Methods::randIn(0, city_info_.get_city_count());

	//把出发城市保存入路径数组中
	path_[0] = cur_city_no_;

	//标识出发城市为已经去过了
	allowed_city[cur_city_no_] = false;

	//已经去过的城市数量设置为1
	moved_city_count_ = 1;
}

void Ant::search()
{
	init(); //蚂蚁搜索前，先初始化

	//如果蚂蚁去过的城市数量小于城市数量，就继续移动
	while (moved_city_count_ < city_count_)
	{
		move();
	}

	//完成搜索后计算走过的路径长度
	calPathLength();
}

void Ant::move()
{
	int city_no = chooseNextCity(); //选择下一个城市

	path_[moved_city_count_] = city_no; //保存蚂蚁走的路径
	allowed_city[city_no] = false;//把这个城市设置成已经去过了
	cur_city_no_ = city_no; //改变当前所在城市为选择的城市
	++moved_city_count_; //已经去过的城市数量加1
}

int Ant::chooseNextCity()
{
	int nSelectedCity = -1; //返回结果，先暂时把其设置为-1

	//==============================================================================
	//计算当前城市和没去过的城市之间的信息素总和

	double total = 0.0;
	QVector<double> prob(city_count_); //保存各个城市被选中的概率
	
	for (int i = 0; i < city_count_; i++)
	{
		if (allowed_city[i] == true) //城市没去过
		{
			prob[i] = pow(trial_[cur_city_no_][i], ant_config_.alpha)*
				pow(1.0 / city_info_.getDistance(cur_city_no_,i), ant_config_.beta); //该城市和当前城市间的信息素
			total = total + prob[i]; //累加信息素，得到总和
		}
		else //如果城市去过了，则其被选中的概率值为0
		{
			prob[i] = 0.0;
		}
	}
	
	//==============================================================================
	//进行轮盘选择
	double dbTemp = 0.0;
	if (total > 0.0) //总的信息素值大于0
	{
		dbTemp = Methods::randIn(0.0, total); //取一个随机数

		for (int i = 0; i < city_count_; i++)
		{
			if (allowed_city[i] == true) //城市没去过
			{
				dbTemp = dbTemp - prob[i]; //这个操作相当于转动轮盘，如果对轮盘选择不熟悉，仔细考虑一下
				if (dbTemp < 0.0) //轮盘停止转动，记下城市编号，直接跳出循环



				{
					nSelectedCity = i;
					break;
				}
			}
		}
	}
	//==============================================================================
	//如果城市间的信息素非常小 ( 小到比double能够表示的最小的数字还要小 )
	//那么由于浮点运算的误差原因，上面计算的概率总和可能为0
	//会出现经过上述操作，没有城市被选择出来
	//出现这种情况，就把第一个没去过的城市作为返回结果

	//题外话：刚开始看的时候，下面这段代码困惑了我很长时间，想不通为何要有这段代码，后来才搞清楚。
	if (nSelectedCity == -1)
	{
		for (int i = 0; i < city_count_; i++)
		{
			if (allowed_city[i] == true) //城市没去过
			{
				nSelectedCity = i;
				break;
			}
		}
	}
	
	//==============================================================================
	//返回结果，就是城市的编号
	return nSelectedCity;
}

void Ant::initTrial(int city_count, double init_val/*=1.0*/)
{
	if (trial_)
		releaseTrial();
	city_count_ = city_count;
	trial_ = new double *[city_count];
	for (int i = 0; i < city_count;++i)
	{
		trial_[i] = new double[city_count];
		for (int j = 0; j < city_count;++j)
		{
			trial_[i][j] = init_val;
		}
	}
}

void Ant::releaseTrial()
{
	for (int i = 0; i < city_count_; i++)
	{
		delete[]trial_[i];
	}
	delete[]trial_;
	trial_ = nullptr;
}

void Ant::calPathLength()
{
	path_length_ = 0.0; //先把路径长度置0
	int m = 0;
	int n = 0;

	for (int i = 1; i < city_count_; i++)
	{
		m = path_[i];
		n = path_[i - 1];
		path_length_ = path_length_ + city_info_.getDistance(m,n);
	}

	//加上从最后城市返回出发城市的距离
	n = path_[0];
	path_length_ += city_info_.getDistance(m, n);
}

double Ant::get_path_leangth() const
{
	return path_length_;
}


double Ant::getTrial(int i, int j)
{
	if (i<0 || j<0 || i>city_count_ - 1 || j>city_count_ - 1)
		throw QString("The index is out of range!");
	else
		return trial_[i][j];
}

void Ant::setTrial(int i, int j, double trial)
{
	if (i<0 || j<0 || i>city_count_ - 1 || j>city_count_ - 1)
		throw QString("The index is out of range!");
	else
		trial_[i][j]=trial;
}

int Ant::getPath(int i) const
{
	if (i<0 || i>city_count_ - 1)
		throw QString("The index is out of range!");
	else
		return path_[i];
}

void Ant::savePathToFile(const QString &file)
{
	QFile qfile(file);
	if (!qfile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
		throw QString("can not open or create the file->" + file);
	QTextStream stream(&qfile);
	for (int i = 0; i < city_count_; i++)
	{
		stream << path_[i] << endl;
	}
	stream.flush();
	qfile.close();
}


void Ant::setPathToVector(QVector<int> &path) const
{
	if (path.size() != city_count_)
		path.resize(city_count_);
	for (int i = 0; i < city_count_; i++)
	{
		path[i] = path_[i];
	}
}

void Ant::output()
{
	QFile file("trial.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
	QTextStream stream(&file);
	for (int i = 0; i < city_count_; ++i)
	{
		for (int j = 0; j < city_count_; ++j)
		{
			stream << trial_[i][j] << " ";
		}
		stream << endl;
	}
	stream.flush();
	file.close();
}

int Ant::city_count_ = 0;

double ** Ant::trial_=nullptr;
