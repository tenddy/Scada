#include "monitorsystem.h"
#include <qmessagebox.h>
#include <qtimer.h>
#include <qpushbutton.h>
#include <QLabel>
#include "SettingFiles.h"
#include "channel.h"
#include "configure.h"

MonitorSystem::MonitorSystem(QWidget *parent)
    : QWidget(parent)
{
    QPalette  palette;
    palette.setBrush(QPalette::Background,Qt::black);
    palette.setBrush(QPalette::WindowText,Qt::red);
    setPalette(palette);
    QFrame(this,Qt::FramelessWindowHint);
    ui.setupUi(this);
    
    m_defaultPath = "D:\\data";
   
    m_maxPage = 0;
    initStackPage();
    ui.stackedWidget->setCurrentIndex(0);
    createUI();
    createExcelFile();

    m_CANOpen = new CanOpenProtocol;
    m_CANOpen->run(1000,true);           //open CANOpen

    m_distance = new Distance;
    setSerialPort();                     //open serial port

    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    //setCursor(Qt::BlankCursor);
    showFullScreen();
}

MonitorSystem::~MonitorSystem()
{

}

void MonitorSystem::createUI()
{
    m_pushButtonStatusChange = new QPushButton(QStringLiteral("显示状态界面"));
    statusWidget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(m_pushButtonStatusChange);
    layout->setContentsMargins(0,0,0,10);
    statusWidget->setLayout(layout);
    
    m_process  = new QProcess;
    ui.pushButtonChangedPage->setVisible(false);
    alarmIsviable(false);
    connect(m_pushButtonStatusChange,SIGNAL(clicked()),this,SLOT(on_pushButtonChangedStatusClicked()));
    QTimer *timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(updataValue()));
    connect(timer,SIGNAL(timeout()),this,SLOT(saveData()));
    timer->start(1000);
}

void MonitorSystem::initStackPage()
{
    QVector<BasePage *> pagevect = SettingFiles::ReadFromConfigFile("default.ini");
	for(int i=0; i < pagevect.count(); i++)
    	ui.stackedWidget->addWidget(pagevect[i]);
    m_maxPage = ui.stackedWidget->count();
}

void MonitorSystem::setSerialPort()
{
    Configure  config("default.ini");
    QString port =  config.configureRead("serialPortName").toString();
    QSerialPort::BaudRate  baudRate = QSerialPort::BaudRate(config.configureRead("baudRate").toInt());
    QSerialPort::DataBits  dataBits = QSerialPort::DataBits(config.configureRead("dataBits").toInt());
    QSerialPort::Parity  parity = QSerialPort::Parity(config.configureRead("parity").toInt());
    QSerialPort::StopBits  stopBits = QSerialPort::StopBits(config.configureRead("stopBits").toInt());
    QSerialPort::FlowControl  flowBits = QSerialPort::FlowControl(config.configureRead("flowControl").toInt());
    
    if(m_distance->openSerialPort(port,baudRate,dataBits,parity,stopBits,flowBits))
    {  
        QTimer *time = new QTimer;
        connect(time,SIGNAL(timeout()),this,SLOT(saveDistance()));
        time->start(1000);
    }
}

void MonitorSystem::createExcelFile()
{
    qExcel excel;
    QString fileName ="data"+QDateTime::currentDateTime().toLocalTime().toString("yyyyMMddhhmmss")+".xls";
    m_dataFile = m_defaultPath +"\\" + fileName;
    int pageNum = m_maxPage;
    //pageNum = m_stackwidget->count();
    for(int i= 0; i< pageNum;i++)
    {
        BasePage *page = (BasePage*)ui.stackedWidget->widget(i);
        /*meter*/
        for(int meterpos = page->meterFirstPos();meterpos <= page->meterLastPos();meterpos++)
        {
            QMeter *meter = page->getMeter(meterpos);
            if(!meter)
                continue;
            QString dataName = meter->getTitle();
            if(dataName.isEmpty())
                dataName = meter->getName();
            // QMessageBox::about(0,"channel name",dataName);
            excel.createTable(QString("CREATE TABLE [%1]([TIME] char(20),[VALUE] varchar(10))").arg(dataName),m_dataFile);
            m_channelTitle[meter->getChannel()] = dataName;  
        }
        /*indicator lamp*/
        if(page->LampCounts())
        {
            for(int lampPos = page->lampFirstPos(); lampPos <= page->lampLastPos(); lampPos++)
            {
                IndicatorLamp* lamp = (IndicatorLamp*)page->getMeter(lampPos);
                if(!lamp)
                   continue;
                QString dataName = lamp->getTitle();
                if(dataName.isEmpty())
                    dataName = lamp->getName();
               // QMessageBox::about(0,"channel name",dataName);
                excel.createTable(QString("CREATE TABLE [%1]([TIME] char(20),[VALUE] varchar(10))").arg(dataName),m_dataFile);                                        
                m_channelTitle[lamp->getChannel()] = dataName;
            }
        }      
    }
}

void MonitorSystem::startProcess(QString filePath)
{
    //m_process->start(filePath);
    m_process->startDetached(filePath);
}


//slots
void MonitorSystem::updataValue()
{
    QFile file("D:\\Data\\run.txt");
    bool fileerr = true;;
    if(!file.open(QFile::WriteOnly | QFile::Append | QFile::Text))
        fileerr = false;
    QTextStream out(&file);

    QMap<int,Channel*> chmap = CanOpenProtocol::m_channelMap;
   
    for(int i= 0; i<m_maxPage;i++)
    {
        BasePage *page = (BasePage*)ui.stackedWidget->widget(i);
        /*meter*/
        for(int meterpos = page->meterFirstPos();meterpos <= page->meterLastPos();meterpos++)
        {
            QMeter *meter = page->getMeter(meterpos);
            if(!meter)
                continue;
            int id = meter->getChannel().mid(8).toInt();
            if(chmap.contains(id))
            {
                meter->setValue(chmap[id]->getFloatValue());
                out << "meter:\t" << meter->getChannel() << "\tvalue:"<< chmap[id]->getFloatValue() << "\n";
            }
        }
        /*indicator lamp*/
        if(page->LampCounts())
        {
            for(int lampPos = page->lampFirstPos(); lampPos <= page->lampLastPos(); lampPos++)
            {
               IndicatorLamp* lamp = (IndicatorLamp*)page->getMeter(lampPos);
                if(!lamp)
                    continue;
                 int id = lamp->getChannel().mid(8).toInt();
                if(chmap.contains(id))
              {
                    int val = chmap[id]->getIntValue();
                    if(val == 1)
                        lamp->setState(QMeter::Normal);
                    else if(val == 0)
                        lamp->setState(QMeter::Warning); 
                    out << "meter:\t" << lamp->getChannel() << "\tvalue:"<< chmap[id]->getFloatValue() << "\n";
                }                                        
                else
                    lamp->setState(QMeter::NoData);           
            }
        }      
    }

    file.close();
}

void  MonitorSystem::saveDistance()
{
    QFile file("D:\\Data\\distance.txt");
    bool fileerr = true;;
    if(!file.open(QFile::WriteOnly | QFile::Append | QFile::Text))
        fileerr = false;
    QTextStream out(&file);
	QString time = QDateTime::currentDateTime().toLocalTime().toString("yyyy-MM-dd hh:mm:ss");
    OutputData* data = Distance::tagData;
    out << "time:" << time <<"\tMAC:" <<data->macofTag 
        <<"\tDistance:" << data->distance << "\tMsg:" << data->message << "\n";
    ConnectDB db;
    db.openDB();
    QSqlQuery query;
    query.prepare("INSERT INTO distance VALUES (?,?,?,?)");
    query.bindValue(0,time);
    query.bindValue(1,data->macofTag);
    query.bindValue(2,data->distance);
    query.bindValue(3,data->message);
    if(!query.exec())
        out << "insert data failed\n";
}

void  MonitorSystem::saveData()
{
    static int clock = 0;
    clock++;

    QFile file("D:\\Data\\excellog.txt");
    bool fileerr = true;;
    if(!file.open(QFile::WriteOnly | QFile::Append | QFile::Text))
        fileerr = false;
    QTextStream out(&file);

    qExcel excel;
    QString time = QDateTime::currentDateTime().toLocalTime().toString("yyyy-MM-dd hh:mm:ss");

    QMap<int,Channel*>::iterator chiter;
    for(chiter = CanOpenProtocol::m_channelMap.begin(); chiter != CanOpenProtocol::m_channelMap.end();chiter++)
    {
        if(clock % chiter.value()->getInhibitTime() == 0)
        {
            QString channelName = chiter.value()->getChannelName();
            out << time <<"\t" << channelName << "\tvalue:" << chiter.value()->getStrValue() << "\n";
            QStringList list;
            list << time << chiter.value()->getStrValue();
            bool state = excel.insertData(list,m_channelTitle[channelName],m_dataFile);
            if(!state)
                out << chiter.value()->getChannelName() << ":\tinsert data failed.\n";
        }
    }
    file.close();
}

//mouse event
void MonitorSystem::mousePressEvent(QMouseEvent *e)
{
    int w = width(), h = height();
    int leftboundary = w*3/8, rightboundary = w*5/8;
   /* int centerUp = (h-(rightboundary-leftboundary))/2;
    int centerdown = (h+(rightboundary-leftboundary))/2;*/
    int xPos = e->x(), yPos = e->y();
   
    if(e->button() == Qt::LeftButton)
    {
        if(xPos < leftboundary )
        {
            ui.pushButtonChangedPage->setVisible(false);
            if(ui.stackedWidget->currentIndex() > 0 )
                ui.stackedWidget->setCurrentIndex(ui.stackedWidget->currentIndex()-1);
            else
                ui.stackedWidget->setCurrentIndex(m_maxPage-1);
        }
        else if(xPos > rightboundary)
        {
            ui.pushButtonChangedPage->setVisible(false);
            if(  ui.stackedWidget->currentIndex()  < m_maxPage-1)
                ui.stackedWidget->setCurrentIndex(ui.stackedWidget->currentIndex()+1);
            else
                ui.stackedWidget->setCurrentIndex(0);
        }
        else if((xPos > leftboundary && xPos < rightboundary) && yPos > h/2+w/8)
        {
            ui.pushButtonChangedPage->setVisible(true);
            connect(ui.pushButtonChangedPage,SIGNAL(clicked()),this,SLOT(on_pushButtonChangedPageClicked()));
        }
    }
}

void MonitorSystem::mouseDoubleClickEvent(QMouseEvent *e)
{
    int w = width(), h = height();
    int margin = w/4;
    int leftboundary = w*3/8, rightboundary = w*5/8;
    int centerUp = (h-margin)/2;
    int centerdown = (h+margin)/2;
    if(e->button() == Qt::LeftButton)
    {
        if((e->x() < rightboundary && e->x() > leftboundary) &&
            (e->y() < centerdown && e->y() > centerUp))
            //QMessageBox::about(0,"double clicked", "clicked");
             exitSystem();
    }
}

void MonitorSystem::mouseReleaseEvent(QMouseEvent *e)
{
   int xPos = e->x(), yPos = e->y();
    /*QMessageBox::about(0,"mouse Press","x:"+QString::number(xPos)+",y:"+
        QString::number(yPos)+"\nbutton:"+QString::number(e->button()));*/
}

void MonitorSystem::exitSystem()
{
	
	if(m_process->state() == QProcess::Running)
	{
		QMessageBox a(this);
		a.setText(QStringLiteral("是否退出视频监控程序?"));
		QPushButton *okButton1  = a.addButton(QStringLiteral("退出"),QMessageBox::AcceptRole);
		QPushButton *cannceButton1 =a.addButton(QStringLiteral("取消"),QMessageBox::RejectRole);
		a.exec();
		if(a.clickedButton() == okButton1)
		{
			//m_process->state() = QProcess::NotRunning;
			m_process->NormalExit;
			m_process->close();
			m_process->kill();
		}
    }

    QMessageBox msgBox(this);
    msgBox.setText(QStringLiteral("是否退出无轨设备检测系统?"));
    QPushButton *okButton  = msgBox.addButton(QStringLiteral("退出"),QMessageBox::AcceptRole);
    QPushButton *cannceButton = msgBox.addButton(QStringLiteral("取消"),QMessageBox::RejectRole);
    
    msgBox.exec();

    if(msgBox.clickedButton() == okButton)
    {
		/*if(m_process->state() == QProcess::Running)
			{
				m_process->state()==QProcess::NotRunning;
                m_process->close();
				m_process->kill();
		    }*/

        close();
    }
}

void MonitorSystem::on_pushButtonChangedPageClicked()
{
    setWindowFlags(Qt::Window);
    showMinimized(); 
    statusWidget->setGeometry(0,height()-30,80,20);
    statusWidget->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint); 
    statusWidget->show();
   
}
void MonitorSystem::on_pushButtonChangedStatusClicked()
{
    statusWidget->close();
    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    ui.pushButtonChangedPage->setVisible(false);
    showMaximized();
}

void MonitorSystem::alarmIsviable(bool flag)
{
    ui.alarmLabel->setVisible(flag);
}
void MonitorSystem::showAlarmInfo(QString text)
{
    ui.alarmLabel->setVisible(true);
    ui.alarmLabel->setText(text);
}

