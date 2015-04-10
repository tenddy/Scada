/*
 *
 *
 *
 *
 */
#ifndef INFOMSG_H_
#define INFOMSG_H_
#include <stdio.h>
#include <direct.h>
#include <time.h>
#include <qstring.h>
#include <qobject.h>
class InfoMsg :public QObject
{
private:
	char *m_filename;
	char *m_filepath;

	char *m_logfilename;
	char *m_logfilepath;
	char *m_logmode;

	char *m_errorFileName;
	char *m_errorFilePath;
	char *m_errormode;
public:
	InfoMsg(void);
	~InfoMsg(void);

	bool infoClearFile(const char *filename);	//clear file
	bool info_error(const char *fromat,...);
	bool info(FILE *file ,const char *format,...);
	bool info_log(const char *format,...);
	static char *getCurrentTime(char *time);
	char *testptr(char *buf); 

	void info_read(FILE *file,const char *format,...);
};

#endif