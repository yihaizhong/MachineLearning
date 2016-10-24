
// AO.cpp : �������̨Ӧ�ó������ڵ㡣
#pragma once

#include <iostream>
#include <math.h>
#include <time.h>

const double ALPHA = 1.0; //�������ӣ���Ϣ�ص���Ҫ�̶�
const double BETA = 2.0;   //�������ӣ����м�������Ҫ�̶�
const double ROU = 0.5; //��Ϣ�ز�������

const int N_ANT_COUNT = 34; //��������
const int N_IT_COUNT = 1000; //��������
const int N_CITY_COUNT = 51; //��������

const double DBQ = 100.0; //�ܵ���Ϣ��
const double DB_MAX = 10e9; //һ����־����10��9�η�

double g_Trial[N_CITY_COUNT][N_CITY_COUNT]; //�������м���Ϣ�أ����ǻ�����Ϣ��
double g_Distance[N_CITY_COUNT][N_CITY_COUNT]; //�������м����

//eil51.tsp������������
double x_Ary[N_CITY_COUNT] =
{
	37, 49, 52, 20, 40, 21, 17, 31, 52, 51,
	42, 31, 5, 12, 36, 52, 27, 17, 13, 57,
	62, 42, 16, 8, 7, 27, 30, 43, 58, 58,
	37, 38, 46, 61, 62, 63, 32, 45, 59, 5,
	10, 21, 5, 30, 39, 32, 25, 25, 48, 56,
	30
};

double y_Ary[N_CITY_COUNT] =
{
	52, 49, 64, 26, 30, 47, 63, 62, 33, 21,
	41, 32, 25, 42, 16, 41, 23, 33, 13, 58,
	42, 57, 57, 52, 38, 68, 48, 67, 48, 27,
	69, 46, 10, 33, 63, 69, 22, 35, 15, 6,
	17, 10, 64, 15, 10, 39, 32, 55, 28, 37,
	40
};

//����ָ����Χ�ڵ��������
int rnd(int nLow, int nUpper)
{
	return nLow + (nUpper - nLow)*rand() / (RAND_MAX + 1);
}

//����ָ����Χ�ڵ����������
double rnd(double dbLow, double dbUpper)
{
	double dbTemp = rand() / ((double)RAND_MAX + 1.0);
	return dbLow + dbTemp*(dbUpper - dbLow);
}

//���ظ�������������ȡ����ĸ�����
double ROUND(double dbA)
{
	return (double)((int)(dbA + 0.5));
}

//����������
class CAnt
{
public:
	CAnt(void);
	~CAnt(void);

public:

	int m_nPath[N_CITY_COUNT]; //�����ߵ�·��
	double m_dbPathLength; //�����߹���·������

	int m_nAllowedCity[N_CITY_COUNT]; //ûȥ���ĳ���
	int m_nCurCityNo; //��ǰ���ڳ��б��
	int m_nMovedCityCount; //�Ѿ�ȥ���ĳ�������

public:

	int ChooseNextCity(); //ѡ����һ������
	void Init(); //��ʼ��
	void Move(); //�����ڳ��м��ƶ�
	void Search(); //����·��
	void CalPathLength(); //���������߹���·������

};

//���캯��
CAnt::CAnt(void)
{
}

//��������
CAnt::~CAnt(void)
{
}

//��ʼ����������������ǰ����
void CAnt::Init()
{

	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		m_nAllowedCity[i] = 1; //����ȫ������Ϊû��ȥ��
		m_nPath[i] = 0; //�����ߵ�·��ȫ������Ϊ0
	}

	//�����߹���·����������Ϊ0
	m_dbPathLength = 0.0;

	//���ѡ��һ����������
	m_nCurCityNo = rnd(0, N_CITY_COUNT);

	//�ѳ������б�����·��������
	m_nPath[0] = m_nCurCityNo;

	//��ʶ��������Ϊ�Ѿ�ȥ����
	m_nAllowedCity[m_nCurCityNo] = 0;

	//�Ѿ�ȥ���ĳ�����������Ϊ1
	m_nMovedCityCount = 1;

}

//ѡ����һ������
//����ֵ Ϊ���б��
int CAnt::ChooseNextCity()
{

	int nSelectedCity = -1; //���ؽ��������ʱ��������Ϊ-1

	//==============================================================================
	//���㵱ǰ���к�ûȥ���ĳ���֮�����Ϣ���ܺ�

	double dbTotal = 0.0;
	double prob[N_CITY_COUNT]; //����������б�ѡ�еĸ���

	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		if (m_nAllowedCity[i] == 1) //����ûȥ��
		{
			prob[i] = pow(g_Trial[m_nCurCityNo][i], ALPHA)*pow(1.0 / g_Distance[m_nCurCityNo][i], BETA); //�ó��к͵�ǰ���м����Ϣ��
			dbTotal = dbTotal + prob[i]; //�ۼ���Ϣ�أ��õ��ܺ�
		}
		else //�������ȥ���ˣ����䱻ѡ�еĸ���ֵΪ0
		{
			prob[i] = 0.0;
		}
	}

	//==============================================================================
	//��������ѡ��
	double dbTemp = 0.0;
	if (dbTotal > 0.0) //�ܵ���Ϣ��ֵ����0
	{
		dbTemp = rnd(0.0, dbTotal); //ȡһ�������

		for (int i = 0; i < N_CITY_COUNT; i++)
		{
			if (m_nAllowedCity[i] == 1) //����ûȥ��
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
		for (int i = 0; i < N_CITY_COUNT; i++)
		{
			if (m_nAllowedCity[i] == 1) //����ûȥ��
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


//�����ڳ��м��ƶ�
void CAnt::Move()
{
	int nCityNo = ChooseNextCity(); //ѡ����һ������

	m_nPath[m_nMovedCityCount] = nCityNo; //���������ߵ�·��
	m_nAllowedCity[nCityNo] = 0;//������������ó��Ѿ�ȥ����
	m_nCurCityNo = nCityNo; //�ı䵱ǰ���ڳ���Ϊѡ��ĳ���
	m_nMovedCityCount++; //�Ѿ�ȥ���ĳ���������1
}

//���Ͻ�������һ��
void CAnt::Search()
{
	Init(); //��������ǰ���ȳ�ʼ��

	//�������ȥ���ĳ�������С�ڳ����������ͼ����ƶ�
	while (m_nMovedCityCount < N_CITY_COUNT)
	{
		Move();
	}

	//�������������߹���·������
	CalPathLength();
}


//���������߹���·������
void CAnt::CalPathLength()
{

	m_dbPathLength = 0.0; //�Ȱ�·��������0
	int m = 0;
	int n = 0;

	for (int i = 1; i < N_CITY_COUNT; i++)
	{
		m = m_nPath[i];
		n = m_nPath[i - 1];
		m_dbPathLength = m_dbPathLength + g_Distance[m][n];
	}

	//���ϴ������з��س������еľ���
	n = m_nPath[0];
	m_dbPathLength = m_dbPathLength + g_Distance[m][n];

}


//tsp��
class CTsp
{
public:
	CTsp(void);
	~CTsp(void);

public:
	CAnt m_cAntAry[N_ANT_COUNT]; //��������
	CAnt m_cBestAnt; //����һ�����ϱ����������������������е����Ž��
	//�����ϲ�����������ֻ�������������Ž��

public:

	//��ʼ������
	void InitData();

	//��ʼ����
	void Search();

	//���»�����Ϣ��
	void UpdateTrial();


};


//���캯��
CTsp::CTsp(void)
{
}

CTsp::~CTsp(void)
{
}


//��ʼ������
void CTsp::InitData()
{

	//�Ȱ��������ϵ�·���������ó�һ���ܴ��ֵ
	m_cBestAnt.m_dbPathLength = DB_MAX;

	//�����������м����
	double dbTemp = 0.0;
	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		for (int j = 0; j < N_CITY_COUNT; j++)
		{
			dbTemp = (x_Ary[i] - x_Ary[j])*(x_Ary[i] - x_Ary[j]) + (y_Ary[i] - y_Ary[j])*(y_Ary[i] - y_Ary[j]);
			dbTemp = pow(dbTemp, 0.5);
			g_Distance[i][j] = ROUND(dbTemp);
		}
	}

	//��ʼ��������Ϣ�أ��Ȱѳ��м����Ϣ�����ó�һ��
	//�������ó�1.0�����óɶ��ٶԽ��Ӱ�첻��̫�󣬶��㷨�����ٶ���ЩӰ��
	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		for (int j = 0; j < N_CITY_COUNT; j++)
		{
			g_Trial[i][j] = 1.0;
		}
	}

}




//���»�����Ϣ��
void CTsp::UpdateTrial()
{
	//��ʱ���飬�����ֻ�������������м������µ���Ϣ��
	double dbTempAry[N_CITY_COUNT][N_CITY_COUNT];
	memset(dbTempAry, 0, sizeof(dbTempAry)); //��ȫ������Ϊ0

	//���������ӵ���Ϣ��,���浽��ʱ������
	int m = 0;
	int n = 0;
	for (int i = 0; i < N_ANT_COUNT; i++) //����ÿֻ�������µ���Ϣ��
	{
		for (int j = 1; j < N_CITY_COUNT; j++)
		{
			m = m_cAntAry[i].m_nPath[j];
			n = m_cAntAry[i].m_nPath[j - 1];
			dbTempAry[n][m] = dbTempAry[n][m] + DBQ / m_cAntAry[i].m_dbPathLength;
			dbTempAry[m][n] = dbTempAry[n][m];
		}

		//�����кͿ�ʼ����֮�����Ϣ��
		n = m_cAntAry[i].m_nPath[0];
		dbTempAry[n][m] = dbTempAry[n][m] + DBQ / m_cAntAry[i].m_dbPathLength;
		dbTempAry[m][n] = dbTempAry[n][m];

	}

	//==================================================================
	//���»�����Ϣ��
	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		for (int j = 0; j < N_CITY_COUNT; j++)
		{
			g_Trial[i][j] = g_Trial[i][j] * ROU + dbTempAry[i][j]; //���µĻ�����Ϣ�� = �������Ϣ�� + �����µ���Ϣ��
		}
	}

}


void CTsp::Search()
{

	char cBuf[256]; //��ӡ��Ϣ��

	//�ڵ��������ڽ���ѭ��
	for (int i = 0; i < N_IT_COUNT; i++)
	{
		//ÿֻ��������һ��
		for (int j = 0; j < N_ANT_COUNT; j++)
		{
			m_cAntAry[j].Search();
		}

		//������ѽ��
		for (int j = 0; j < N_ANT_COUNT; j++)
		{
			if (m_cAntAry[j].m_dbPathLength < m_cBestAnt.m_dbPathLength)
			{
				m_cBestAnt = m_cAntAry[j];
			}
		}

		//���»�����Ϣ��
		UpdateTrial();

		//���ĿǰΪֹ�ҵ�������·���ĳ���
		sprintf(cBuf, "\n[%d] %.0f", i + 1, m_cBestAnt.m_dbPathLength);
		printf(cBuf);
	}

}

