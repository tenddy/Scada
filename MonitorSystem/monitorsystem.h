#ifndef MONITORSYSTEM_H
#define MONITORSYSTEM_H

#include <QtWidgets/QWidget>
#include "ui_monitorsystem.h"
#include <qevent.h>
#include <qvector.h>
#include <qprocess.h>
#include <QPoint>

#include "canopenprotocol.h"
#include "distance.h"
#include "qexcel.h"


class MonitorSystem : public QWidget
{
    Q_OBJECT

public:
    MonitorSystem(QWidget *parent = 0);
    ~MonitorSystem();

    void alarmIsviable(bool flag);
    void showAlarmInfo(QString text);
    void startProcess(QString filePath);
protected:
	//void resizeEvent(QResizeEvent *);  
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);

private:
    QPoint m_offset;
    QPoint m_cursorCurrentPos;
    Ui::MonitorSystemClass ui;
    QWidget *statusWidget;
    QPushButton *m_pushButtonStatusChange;
    QProcess *m_process;
    QString m_defaultPath;
    QString m_dataFile;
    QMap<QString,QString> m_channelTitle;
    int m_maxPage;
    CanOpenProtocol *m_CANOpen;
    Distance    *m_distance;
    
    void createUI();
	void initStackPage();
    void setSerialPort();
    void createExcelFile();
    void exitSystem();
   
signals:
    void pageChange();
public slots:
    void updataValue();
    void saveDistance();
    void saveData();
    void on_pushButtonChangedPageClicked();
    void on_pushButtonChangedStatusClicked();
    
};

#endif // MONITORSYSTEM_H
