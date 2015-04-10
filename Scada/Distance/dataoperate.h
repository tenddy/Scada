#ifndef DATAOPERATE_H
#define DATAOPERATE_H

#include <QString>
#include <QTime>

class DataOperate
{
public:
    DataOperate();
    ~DataOperate();
   static double getDistance(QString data);                   //距离获取函数
   static QString getMac(QString data);                       //mac地址获取函数
   static double getTime();
};

#endif // DATAOPERATE_H
