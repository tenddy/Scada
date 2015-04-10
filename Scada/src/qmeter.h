
/*
**  @description:
**	仪表抽象基类，用于创建仪表派生类，并保存仪表的基本参数
**  @parameter:NULL
**
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
#ifndef QMETER_H
#define QMETER_H

#include <QtWidgets/QWidget>
#include <qpoint.h>

class QMeter : public QWidget
{
	Q_OBJECT

public:
	//仪表类型
	enum Type{
		EngineMeter = 1,	  //Enginemeter
		FuelLevel	= 2,	 // fuelLevel
        Meter		= 3,     //dial
        Thermometer	= 4,     //thermo-graph
        Lamp		= 5      //pilot lamp
	};
	//运行状态
	enum State{
		NoData = 0,		  //无数据
		Normal = 1,		  //运行正常
		Warning = 2,	  //预警
		Alarm = 3		  //报警
	};
	QMeter(QString name ,QString title,Type type = Meter, QWidget *parent = 0);
	virtual ~QMeter();

	Type getType() {return m_type;}
	State getState() {return m_state;}
	QString getName() {return m_name;}
	QString getTitle() { return m_title;}
	QString getChannel() { return m_channel;}
	double getValue() {return m_value;}
	double getScale() {return m_scale;}
	QPoint getCenter() {return m_center;}
	bool getVisiable() {return m_visible;}

	//virtual double Radius() const = 0;  
	//virtual int getComponents() const = 0;
 //   virtual QString getUnits()const = 0;
	//virtual int Precision() const =0;
	//virtual double Rate() const = 0;
	//virtual int startAngle() const =0 ;
 //   virtual int endAngle() const = 0;
	//virtual double Factor() const =0;
	//virtual int InnerScaleSteps() =0;
	//virtual int Strech() =0;
	//virtual void changeValue(int ) = 0;

protected:
	virtual void paintEvent(QPaintEvent *) = 0;	  //纯虚函数，绘制仪表，重载QWidget中paintEvent
signals:
	void ScaleChanged(double);
	void stateChanged();
	void visiableChanged();
public slots:
	virtual void setType(Type) = 0;
	virtual void setState(State) = 0;
	virtual void setName(QString) = 0;
	virtual void setTitle(QString) = 0;
	virtual void setChannel(QString) = 0;
	virtual void setValue(double) = 0;
	virtual void setScale(double) = 0 ;
	virtual void setCenter(QPoint) = 0;
	virtual void setCenter(double,double) = 0;
	virtual void setMeterVisible(bool) = 0;   
protected:

	QString m_name;			 //仪表名（只能以字符命名）
	Type m_type;			 //仪表类型
	State  m_state;			 //运行状态
	QString m_title;		 //仪表显示名称 (可以是中文汉字和字符命名）
	QString m_channel;		 //获取数据通道 ，与硬件连接
	double m_value;			 //仪表当前值
	double m_scale;			 //显示比例
	QPoint m_center;		 //中心点
	bool m_visible;		     //是否隐藏

};

#endif // QMETER_H
