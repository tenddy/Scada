#ifndef CHANNEL_H
#define CHANNEL_H

#include <QObject>

class Channel
{

public:
    
    Channel(int id = 0, bool adFlag = true, float minVal = 0, float maxVal = 1, int inhibit = 1);
    ~Channel();
  
    int getChannelId() ;
    QString getChannelName() const ;
    bool IsDigit() const;
    bool IsAnalog() const ;
    QString getStrValue() const ;
    int getIntValue() const ;
    double getFloatValue(int precise = 2) const;
    float getMinValue() const ;
    float getMaxValue() const ;
    int   getInhibitTime() const;

    void setAnalogValue(float val,int precise = 2, bool adFlag = true);
    void setDigitValue(int val, bool adFlag = false);

    void print ();     // for test
private:
    int  m_id; //channel id
    QString m_name; //channel name: "Channle_"+id
    bool m_ADFlag; // bit flag of analog/digit data, true represent analog data while false represent digit data
    QString m_strVal; //real value 
    float m_minVal;  //minimum value of sensor can detect
    float m_maxVal;  //maximize value of sensor can detect
    int   m_inhibit; //interval time of saving data.(minimum time is 1s)  
};

#endif // CHANNEL_H
