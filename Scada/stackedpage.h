#ifndef STACKEDPAGE_H
#define STACKEDPAGE_H

#include <QObject>
#include <qvector.h>
#include "src\basepage.h"
#include "src\qmeter.h"
#include <qlist.h>
class StackedPage :QObject 
{
	Q_OBJECT

public:
	StackedPage() {}
	StackedPage(QVector<BasePage*> pages);
	StackedPage(QList<BasePage*> pages );
	~StackedPage();

	void initPages();
	void insertPage(BasePage *page,int index = 0);
	void insertMeter(QMeter *meter,int page = 1, int pos = 1);
	void adjustMeter(int pageIndex,int meterCurrent, int meterPrevious);
	//void adjustMeter(int pageCurrent,int pagePrevious, int meterCurrent, int meterPrevious);
	int getCounts() {return m_vectPages.size();}
	BasePage* getPage(int index) {return m_vectPages[index];}
	void clearStackedPages();
private:
	QVector<BasePage *> m_vectPages;
	
public slots:
    void adjustPages(int i, int preMeterNum, int curMeterNum, bool lampFlag);
	bool setMeterPos(int pageNum, QString meterName, int pos);
};

#endif // STACKEDPAGE_H
