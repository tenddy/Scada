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
    char *m_mode;

	char *m_logfilename;
	char *m_logfilepath;
	char *m_logmode;

	char *m_errorFileName;
	char *m_errorFilePath;
	char *m_errormode;
public:
	InfoMsg(void);
	InfoMsg(const char * fileName, const char *mode = "a");
    ~InfoMsg(void);

	bool infoClearFile(const char *filename);	//clear file
	bool info_error(const char *fromat,...);
	bool info(FILE *file ,const char *format,...);
	bool info_log(const char *format,...);
    static char *getCurrentTime(char *time);
	char *testptr(char *buf); 

    bool info_write(const char *format, ...);
	void info_read(FILE *file,const char *format,...);
};

#endif