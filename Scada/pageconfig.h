#ifndef PAGECONFIG_H
#define PAGECONFIG_H

#include <QWidget>
#include "ui_pageconfig.h"
#include <qlist.h>
#include "src\qbasemeter.h"
#include <qtreewidget.h>
#include <qtreewidget.h>
#include "meterconfigdlg.h"
#include "src\thermometerconfig.h"
#include "indicatorconfigdlg.h"
#include "pageconfigdlg.h"
#include "stackedpage.h"

class PageConfig : public QWidget
{
	Q_OBJECT

public:
	PageConfig(QWidget *parent = 0);
	~PageConfig();
protected:
	void createUI();
private:
	Ui::PageConfig PageConfigUI;

	QTreeWidgetItem *m_currentItem;
	StackedPage *m_stackedPages;
	PageConfigDlg *m_pageConfigDlg;
	MeterConfigDlg *m_meterConfigDlg ;
	ThermoMeterConfig *m_thermoConfigDlg;
	IndicatorConfigDlg *m_lampConfigDlg;

	void initTreeWidget(QTreeWidget *treewidget);
	void initTreeWidget(StackedPage *stackedPages);

public slots:
	void updatePage();
	void on_tabWidgetSelected(int );
	void on_treeWidgetItemClicked(QTreeWidgetItem *);
	void on_updatePageName(QString);
    void on_updateMeterName(QString);
	void on_meterPosAdjust(int current, int previous);
	void on_pageAdjust(int preMeterNum, int curMeterNum, bool lampFlag);
	void savePageConfig(QString filepath = "default.ini");
};

#endif // PAGECONFIG_H
