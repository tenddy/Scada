#ifndef ENGINEMETER_H
#define ENGINEMETER_H

#include "qbasemeter.h"

class EngineMeter : public QBaseMeter
{
	Q_OBJECT

public:
	EngineMeter(const QString name = "EngineMeter",QString title ="×ªËÙ±í",const QMeter::Type type = QMeter::EngineMeter, QWidget *parent=0);
	~EngineMeter();
	int runtime() {return m_runtime;}

	void drawRuntime(QPainter *);
private:
	void paintEvent(QPaintEvent *);
	int m_runtime;

public Q_SLOTS:
	void setRuntime(int time); 
private slots:
	void setRuntime();
	void changeValue();
protected:
	virtual void drawNumericValue(QPainter *painter,int flags = Qt::AlignCenter, QPen pen = QPen(Qt::gray));
};

#endif // ENGINEMETER_H
