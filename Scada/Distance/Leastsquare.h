//***************************************************/
//*最小二乘法，可以使用定长数组和vector两种参数构造，返回值为表
//*达式以及系数a。
//***************************************************/

#ifndef LEASTSQURE_H
#define LEASTSQURE_H

#include <QVector>

class LeastSquare
{
public:
    LeastSquare(QVector<double>& x,QVector<double>& y);
    LeastSquare(double x[],double y[],int n);
    ~LeastSquare();

    double predict( double x)
    {
        return a*x + b;
    }

    double speed()
    {
        return a;
    }

private:
    double a,b;
};
#endif // LEASTSQURE_H
