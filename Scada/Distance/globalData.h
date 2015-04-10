#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include <QString>
#include <QVector>


enum warning{normal,block,danger,signal_lost,OutOfRange};

struct Tag{
//距离相关矢量
QVector<double> dis;
QVector<double> pre;
QVector<double> fin;
double operdis[5];
double lostdis[3];

//时间相关矢量
QVector<double> ortime;//
QVector<double> zetime;//
QVector<double> pretime;//
double opertime[5];
double losttime[3];

//预测用中间变量
double predictdis;
double predicttime;
double lostspeed;

//Mac地址
QString tagmac;

//计数量
int testTimes;//���Դ���
int losttimes;//��������
int oddtimes;//����ֵ����

//标示量
bool islost;//�����Ƿ񶪰�
bool iserr;//�����Ƿ���λ������������

//报警信号
warning alarm;
};

static QVector<QString> Macs;

static QVector<Tag*> Tagvec;

static bool isMacExist;

struct OutputData
{
    double distance;
    double obtaintime;
    QString macofTag;
    warning message;
};
#endif // GLOBALDATA_H
