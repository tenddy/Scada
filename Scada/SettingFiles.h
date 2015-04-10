#ifndef SETTINGFILES_H_
#define SETTINGFILES_H_
#include "connectdb.h"
#include "src\basepage.h"
#include "stackedpage.h"
#include <qvector.h>

class SettingFiles
{
public:
	SettingFiles(void);
	SettingFiles(QString filePath );
	~SettingFiles(void);
	SettingFiles(const SettingFiles& settingfiles);
	static void WriteToConfigFile(QString filepath,ConnectDB db, QString tableName = "configdb");
	static void SaveToConfigFile(StackedPage *, QString filepath = "default.ini");
	static QVector<BasePage*> ReadFromConfigFile(QString filepath);
private:
	QString m_settingFile;

    static void saveSerialPortParam(QString filepath = "default.ini");
};

#endif //SETTINGFILES_H_
