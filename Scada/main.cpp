#include "scada.h"
#include <QtWidgets/QApplication>
#include "connectdb.h"
#include <qmessagebox.h>
#include "src\basepage.h"
#include "src\qmeter.h"
#include "canopenprotocol.h"
#include "thermometer.h"
//#include "qbasemeter.h"
#include "indicatorlamp.h"
//#include "stackedpage.h"
//#include "SettingFiles.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
    CanNode node;
    node.initCanNode();
  
   /* BasePage page(1);
    ThermoMeter *therm  = new ThermoMeter;
    QMessageBox::about(0,"center","x:"+QString::number(therm->getCenter().x())+
        ",y:"+QString::number(therm->getCenter().y()));
    page.addMeter(therm,1);
    QMessageBox::about(0,"center","x:"+QString::number(therm->getCenter().x())+
        ",y:"+QString::number(therm->getCenter().y()));*/


	Scada w;
	w.show();

	return a.exec();
}
