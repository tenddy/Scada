#ifndef FUELMETER_H
#define FUELMETER_H

#include "qbasemeter.h"

class FuelMeter : public QBaseMeter
{
	Q_OBJECT

public:
	FuelMeter(QString name = "fuelMeter", QString title = QStringLiteral("смн╩╠М"), QMeter::Type type= QMeter::FuelLevel,QWidget *parent =0);
	~FuelMeter();

private:
	void paintEvent(QPaintEvent *);
	void drawLogo(QPainter *);
	void drawEF(QPainter *);
private slots:


};

#endif // FUELMETER_H
