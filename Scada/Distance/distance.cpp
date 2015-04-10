#include "distance.h"
#include <qfile.h>
#include <qtextstream.h>
#include "Leastsquare.h"

OutputData* Distance::tagData = new OutputData;
Distance::Distance(QObject *parent)
    : QObject(parent)
{
    serial = new QSerialPort;
    connect(serial,SIGNAL(readyRead()),this,SLOT(readData()));
}

Distance::~Distance()
{

}

bool Distance::openSerialPort(QString name,quint32 baudRate,QSerialPort::DataBits dataBits,
    QSerialPort::Parity parity,QSerialPort::StopBits stopBits, QSerialPort::FlowControl flowControl)
{
    serial->setPortName(name);
    serial->setBaudRate(baudRate);
    serial->setDataBits(dataBits);
    serial->setParity(parity);
    serial->setStopBits(stopBits);
    serial->setFlowControl(flowControl);
    if(serial->open(QIODevice::ReadWrite))
        return true;
    else
        return false;
}  

void Distance::closeSeialPort()
{
    serial->close();
}

QString Distance::read()
{
    if(dataBuffer.isEmpty())
        return QString();
    return dataBuffer.dequeue();
}

QStringList Distance::readAll()
{
    QStringList datalist;
    while(dataBuffer.size())
        datalist << dataBuffer.dequeue();

    return datalist;
}

void Distance::writeData(const QByteArray &data)
{
    serial->write(data);
}

void Distance::readData()
{
	serial->waitForReadyRead(100);
    QByteArray data = serial->readAll();
	QString HexData = data.toHex().toUpper();                                                 //转化为16进制显示的字符串
	

    while(dataBuffer.size() > 99)
        dataBuffer.dequeue();
   
    //显示字符串，调试用  
    QFile file("1.txt");
	file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text);
    QTextStream out(&file);

    for (int i=0;i<HexData.length();i=i+2)                                      //对字符串中连一起的字符进行判别
    {
        if(HexData.mid(i,2)=="8F")                                              //找报文头8F
        {
            out<< "buf:" << buf<<endl;
			dataBuffer.enqueue(buf);
			emit readReady();
            buf.clear();                                                        //在找到8f时清空buf字符串
            buf+=HexData.mid(i,2)+" ";                                          //将8f存入buf字符串首位，每个字符串后加空格
        }
        else if(HexData.mid(i,4)=="0D0A")                                       //找终止符0d0a
        {
            if(buf.length()==72)	                                           //在没加0d0a的情况下，判断buf的长度，不是24则视作丢包
            {
				buf+="\n";
				
			}
            else
                buf.clear();
            
			/************直接copy C++*********************/

            QString curmac=DataOperate::getMac(buf);
            judgeMac(curmac);

			tagnum=0;
            if(!isMacExist)													//��ǰMac��ַ������
            {
                Tag *tag=new Tag;
                tag->tagmac=curmac;
                Tagvec.push_back(tag);
                tagOperate(Tagvec[Tagvec.size()-1],buf);
                QTimer *t = new QTimer;
                vectTimer.push_back(t);
                connect(t,SIGNAL(timeout()),this,SLOT(judgeLost()));
                t->start(250);
            }
            else
            {
                for(int i=0;i<Tagvec.size();i++)
                {
                    if(!curmac.compare(Tagvec[i]->tagmac))						//compareʱ����Ϊfalse
                        tagnum=i;
                }
                tagOperate(Tagvec[tagnum],buf);
                vectTimer[tagnum]->start(250);
            }
                i=i+2;
        }
        else
        {
            buf+=HexData.mid(i,2)+" ";
        }   
    }
    
}

void Distance::handleError(QSerialPort::SerialPortError error)
{

}

void Distance::tagOperate(Tag *tag, QString tagData)
{
		tag->testTimes++;
        double distance=DataOperate::getDistance(tagData);
        tag->dis.push_back(distance);

        double ctime=DataOperate::getTime();
        tag->ortime.push_back(ctime);
        double ztime=ctime-tag->ortime[0];
        tag->zetime.push_back(ztime);

        if(tag->dis.size()<=5)
        {
            tag->fin.push_back(distance);
        }

        if (tag->fin.size()>=5)
        {
            if(tag->losttimes>=10)
            {
                for(int i=0;i<=4;i++)
                {
                    tag->operdis[i]=tag->dis[tag->dis.size()-1];
                    tag->opertime[i]=tag->zetime[tag->zetime.size()-1];
                }
            }
            else
            {
                for(int i=0;i<=4;i++)
                {
                    tag->operdis[i]=tag->fin[tag->fin.size()-(5-i)];
                    tag->opertime[i]=tag->zetime[tag->fin.size()-(5-i)];
                }
            }

            predict(tag);

            if(abs(tag->dis[tag->dis.size()-1]-tag->fin[tag->fin.size()-1])<5)
            {
               tag->fin.push_back(tag->dis[tag->dis.size()-1]);
               tag->oddtimes=0;
            }
            else
            {
               tag->fin.push_back(tag->pre[tag->pre.size()-1]);
               tag->oddtimes++;
            }
        }

        if (tag->losttimes>=5)
        {
            if(tag->lostspeed>0&&tag->fin[tag->fin.size()-tag->losttimes-1]>50)
            {
                tag->alarm=signal_lost;
            }
            else
            {
                tag->alarm=OutOfRange;
            }
        }

        if (tag->fin[tag->fin.size()-1]<15)
            tag->alarm=danger;

        if (tag->oddtimes>=5)
            tag->alarm=block;

        tag->losttimes=0;
        /**********************调试显示**************************/
       /* QString preshow;
        QString timeshow;
        QString disshow;
        QString finshow;
        QString macshow;
        if(tag->dis.size()>1)
        console->showHexdata(disshow.setNum(tag->dis[tag->dis.size()-1]));
        if(tag->pre.size()>1)
        console->showHexdata(preshow.setNum(tag->pre[tag->pre.size()-1]));
        if(tag->fin.size()>1)
        console->showHexdata(finshow.setNum(tag->fin[tag->fin.size()-1]));
        if(tag->zetime.size()>1)
        console->showHexdata(timeshow.setNum(tag->zetime[tag->zetime.size()-1]));
        console->showHexdata(tag->tagmac);*/
        /*******************************************************/
        outPut(Tagvec[tagnum]);
}

void Distance::judgeMac(QString wholeMac)
{
  if(Macs.empty())
         isMacExist=false;
    else
        {
         for(int i=0;i<Macs.size();i++)
            {
                if(wholeMac.compare(Macs[i])==0)
                    {
                        isMacExist=true;
                        break;
                    }
                else
                        isMacExist=false;
            }
        }

    if(!isMacExist)
        Macs.push_back(wholeMac);
}

void Distance::judgeLost()
{
   if(Tagvec[tagnum]->testTimes==0)
   {
       Tagvec[tagnum]->losttimes++;
       if (Tagvec[tagnum]->fin.size()>=5)
       {
               for(int i=0;i<=4;i++)
               {
                   Tagvec[tagnum]->operdis[i]=Tagvec[tagnum]->fin[Tagvec[tagnum]->fin.size()-(5-i)];
                   Tagvec[tagnum]->opertime[i]=Tagvec[tagnum]->zetime[Tagvec[tagnum]->fin.size()-(5-i)];
               }
            predict(Tagvec[tagnum]);
            Tagvec[tagnum]->fin.push_back(Tagvec[tagnum]->pre[Tagvec[tagnum]->pre.size()-1]);	//ȡ������ȡԤ������
            Tagvec[tagnum]->zetime.push_back(Tagvec[tagnum]->predicttime);                       //Ԥ��ʱ������tag->zetime
       }
       outPut(Tagvec[tagnum]);
    }
}

void Distance::predict(Tag *tag)
{
    LeastSquare ls(tag->opertime,tag->operdis,5);
    tag->predicttime=tag->opertime[4]+0.25;
    tag->predictdis=ls.predict(tag->predicttime);
    tag->pre.push_back(tag->predictdis);
}

void Distance::outPut(Tag *tag)
{
    tagData->distance=tag->fin[tag->fin.size()-1];
    tagData->macofTag=tag->tagmac;
    tagData->obtaintime=tag->zetime[tag->zetime.size()-1];
    tagData->message=tag->alarm;
}
