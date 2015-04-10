#include "stackedpage.h"
#include <qmessagebox.h>
//#include "InfoMsg.h"

StackedPage::StackedPage(QVector<BasePage*> pages)
	:m_vectPages(pages)
{
	
}

StackedPage::StackedPage(QList<BasePage*> pages)
{
	for(int i=0;i<pages.count();i++)
		m_vectPages.append(pages[i]);
}

StackedPage::~StackedPage()
{

}

void StackedPage::clearStackedPages()
{
	m_vectPages.clear();
}

void StackedPage::initPages()
{
	/*while(count())
		removeWidget(widget(0));

	foreach(BasePage * page,m_vectPages)
		insertWidget(count(),page);*/
}

void StackedPage::insertPage(BasePage *page,int index)
{
	m_vectPages.insert(index,page);
	//m_vectPages.append(page);
	//insertWidget(index,page);
	//setCurrentIndex(0);
}

void StackedPage::insertMeter(QMeter *meter, int pageNum , int pos)
{
	BasePage *page  = m_vectPages[pageNum];
	page->addMeter(meter,pos);
	//adjustPages(pageNum);
}

void StackedPage::adjustMeter(int pageNum, int current, int previous)
{
	//QMessageBox::about(0,"num",QString("Adjust,c:%1,p:%2").arg(current).arg(previous));
	
	//page->setMeterPos(
}

/*
**  @description:
**	Setting meters' position
**  @parameter:
**
**  @return value:bool
**	Return false if m_vectPages doesn't have the page which page id is pageNum  or don't find meter on the page
**	Return true if it can place the meter on new position(pos).
**  author:teddy.tu
**  date:
**
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
bool StackedPage::setMeterPos(int pageNum, QString meterName, int pos)
{
	 BasePage *page = m_vectPages[pageNum];
	 if(!page || page->getMeter(pos))  //
		 return false;
	 page->setMeterPos(meterName,pos);
	 return true;
}

/*
**  @description:
**	Move the redundancy meters to next page when the current page can't place the meters.
**	@parameter:
**		@param startPage: the first page to adjust.(startPage starts from 0)
**		@param preMeterNum: the previous count of meters(except lamps) on current page
**		@param curMeterNum: the current count of meters(except lamps) on current page
**		@param lampFlag: the flag of lamps whether is visible or not.
**			lampFlag = true ===> lamps are visible ; lampFlag = false ===> lamps are invisible
**  @return value:NULL
**
**  author:teddy.tu
**  date:
**  Copyright(C) teddy.tu
**  All rights reserved.
*/ 
void StackedPage::adjustPages(int startPage,int preMeterNum, int curMeterNum, bool lampFlag)
{
	//InfoMsg info;
	//QMessageBox::about(0,"adjust","adjust:"+QString::number(startPage)+m_vectPages[startPage]->pageName());
	//if(i >= m_vectPages)
	BasePage *currentPage = m_vectPages[startPage];	   //pointer of current page
	BasePage *nextPage;								   //pointer of next page
	if(startPage<m_vectPages.size()-1)
		nextPage = m_vectPages[startPage+1];
	else											   //if current page is the last page,it will create a new page
	{
		nextPage = new BasePage(m_vectPages.size()+1);	 //page Id start from 1.
		m_vectPages.push_back(nextPage);
	}
	bool flags = false;								//the flag of whether current page is adjusted.
	int currentMaxMeter = currentPage->MaxMeters();
	int nextMaxMeter = nextPage->MaxMeters();
	//QMessageBox::about(0,"adjust","1");
	//info.info_log("\npre:%d,cur:%d\n",preMeterNum,curMeterNum);
	//info.info_log("before adjust,meter:%d,lamps:%d,lastlamp:%d\n",currentPage->MaxMeters(),currentPage->MaxLamps(),currentPage->lampLastPos());
	//adjust meters
	while(currentPage->meterLastPos() > currentMaxMeter)
	{	
		//QMessageBox::about(0,"adjust","adjust meters:"+QString::number(startPage));
		flags = true;
		if(nextPage->meterFirstPos() == 1)
			nextPage->moveMeterSeial();
		//QMessageBox::about(0,"adjust","1-2");
		/*info.info_log("lastmeter:%d\n",currentPage->meterLastPos());
		QMeter *meter = currentPage->getMeter(currentPage->meterLastPos());
		info.info_log("meter:%p\n",meter);*/
		nextPage->addMeter(currentPage->getMeter(currentPage->meterLastPos()),1);
		//info.info_log("curpage:%p,nextpage:%p\n",currentPage->getMeter(currentPage->meterLastPos()),nextPage->getMeter(1));
		currentPage->deleteMeter(currentPage->meterLastPos());
	}
	//QMessageBox::about(0,"adjust","2");
	currentPage->moveLampSerial(curMeterNum-preMeterNum);
	//QMessageBox::about(0,"adjust","3");
	//adjust lamps
	//info.info_log("after move meter,meter:%d,lamps:%d,lastlamp:%d\n",currentPage->MaxMeters(),currentPage->MaxLamps(),currentPage->lampLastPos());
	while(currentPage->LampCounts() && (currentPage->lampLastPos() > currentPage->MaxLamps() + currentMaxMeter))
	{
		//QMessageBox::about(0,"lamps", QString::number(currentPage->MaxLamps() + currentMaxMeter));
		flags = true;
		if(nextPage->lampFirstPos() == currentMaxMeter+1)
			nextPage->moveLampSerial();
		nextPage->addMeter(currentPage->getMeter(currentPage->lampLastPos()),nextMaxMeter+1);
		currentPage->deleteMeter(currentPage->lampLastPos());
	}
	//QMessageBox::about(0,"adjust","4");
	//QMessageBox::about(this,"adjust","adjust finish:"+QString::number(startPage));
	if(flags)
		adjustPages(startPage+1,nextPage->MaxMeters(),nextPage->MaxMeters(),nextPage->getLampsEnabled());
	else if(nextPage->Counts() == 0)	//current page doesn't adjust any meters, 
	{									//if there is none meters on next page, delete the last page
		m_vectPages.removeLast();
		delete nextPage;
		nextPage = NULL;
	}
	//QMessageBox::about(0,"adjust","5");
		//QMessageBox::about(this,"adjust","adjust over!!!");
}
