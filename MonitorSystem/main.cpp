#include "monitorsystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QApplication::setOverrideCursor(Qt::BlankCursor);
    MonitorSystem *w = new MonitorSystem; 
	w->show();
	w->startProcess("D:\\Scada_v5\\Win32\\Release\\video\\Test2.exe");
    
    return a.exec();
}
