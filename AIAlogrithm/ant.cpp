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

	//���ѡ��һ����������
	cur_city_no_ = Methods::randIn(0, city_info_.get_city_count());

	//�ѳ������б�����·��������
	path_[0] = cur_city_no_;

	//��ʶ��������Ϊ�Ѿ�ȥ����
	allowed_city[cur_city_no_] = false;

	//�Ѿ�ȥ���ĳ�����������Ϊ1
	moved_city_count_ = 1;
}

void Ant::search()
{
	init(); //��������ǰ���ȳ�ʼ��

	//�������ȥ���ĳ�������С�ڳ����������ͼ����ƶ�
	while (moved_city_count_ < city_count_)
	{
		move();
	}

	//�������������߹���·������
	calPathLength();
}

void Ant::move()
{
	int city_no = chooseNextCity(); //ѡ����һ������

	path_[moved_city_count_] = city_no; //���������ߵ�·��
	allowed_city[city_no] = false;//������������ó��Ѿ�ȥ����
	cur_city_no_ = city_no; //�ı䵱ǰ���ڳ���Ϊѡ��ĳ���
	++moved_city_count_; //�Ѿ�ȥ���ĳ���������1
}

int Ant::chooseNextCity()
{
	int nSelectedCity = -1; //���ؽ��������ʱ��������Ϊ-1

	//==============================================================================
	//���㵱ǰ���к�ûȥ���ĳ���֮�����Ϣ���ܺ�

	double total = 0.0;
	QVector<double> prob(city_count_); //����������б�ѡ�еĸ���
	
	for (int i = 0; i < city_count_; i++)
	{
		if (allowed_city[i] == true) //����ûȥ��
		{
			prob[i] = pow(trial_[cur_city_no_][i], ant_config_.alpha)*
				pow(1.0 / city_info_.getDistance(cur_city_no_,i), ant_config_.beta); //�ó��к͵�ǰ���м����Ϣ��
			total = total + prob[i]; //�ۼ���Ϣ�أ��õ��ܺ�
		}
		else //�������ȥ���ˣ����䱻ѡ�еĸ���ֵΪ0
		{
			prob[i] = 0.0;
		}
	}
	
	//==============================================================================
	//��������ѡ��
	double dbTemp = 0.0;
	if (total > 0.0) //�ܵ���Ϣ��ֵ����0
	{
		dbTemp = Methods::randIn(0.0, total); //ȡһ�������

		for (int i = 0; i < city_count_; i++)
		{
			if (allowed_city[i] == true) //����ûȥ��
			{
				dbTemp = dbTemp - prob[i]; //��������൱��ת�����̣����������ѡ����Ϥ����ϸ����һ��
				if (dbTemp < 0.0) //����ֹͣת�������³��б�ţ�ֱ������ѭ��



				{
					nSelectedCity = i;
					break;
				}
			}
		}
	}
	//==============================================================================
	//������м����Ϣ�طǳ�С ( С����double�ܹ���ʾ����С�����ֻ�ҪС )
	//��ô���ڸ�����������ԭ���������ĸ����ܺͿ���Ϊ0
	//����־�������������û�г��б�ѡ�����
	//��������������Ͱѵ�һ��ûȥ���ĳ�����Ϊ���ؽ��

	//���⻰���տ�ʼ����ʱ��������δ����������Һܳ�ʱ�䣬�벻ͨΪ��Ҫ����δ��룬�����Ÿ������
	if (nSelectedCity == -1)
	{
		for (int i = 0; i < city_count_; i++)
		{
			if (allowed_city[i] == true) //����ûȥ��
			{
				nSelectedCity = i;
				break;
			}
		}
	}
	
	//==============================================================================
	//���ؽ�������ǳ��еı��
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
	path_length_ = 0.0; //�Ȱ�·��������0
	int m = 0;
	int n = 0;

	for (int i = 1; i < city_count_; i++)
	{
		m = path_[i];
		n = path_[i - 1];
		path_length_ = path_length_ + city_info_.getDistance(m,n);
	}

	//���ϴ������з��س������еľ���
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
