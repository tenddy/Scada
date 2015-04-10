#include "dataoperate.h"

DataOperate::DataOperate()
{
}

//距离值获取
double DataOperate::getDistance(QString data)
{
    QString hun=data.mid(21,2);
    QString one=data.mid(24,2);
    QString poi=data.mid(27,2);
    int hundred=hun.toInt();
    int once=one.toInt();
    int point=poi.toInt();
    double distance=hundred*100+once+point*0.01;
    return distance;
}

//Mac地址获取
QString DataOperate::getMac(QString data)
{
    QString macone=data.mid(42,2);
    QString mactwo=data.mid(45,2);
    QString macthr=data.mid(48,2);
    QString wholeMac=macone+mactwo+macthr;
    return wholeMac;
}

//时间获取
double DataOperate::getTime()
{
    QTime time = QTime::currentTime();
    double originTime=time.hour()*3600+time.minute()*60+time.second()+time.msec()*0.001;
    return originTime;
}


