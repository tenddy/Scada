#include "InfoMsg.h"
#include <stdarg.h>
#include <string.h>

InfoMsg::InfoMsg(void)
{
	m_logfilename = "log.txt";
	m_logfilepath = "";
	m_logmode = "a";

	m_errorFileName = "error.txt";
	m_errorFilePath = "";
	m_errormode = "a";
}

InfoMsg::InfoMsg(const char *fileName, const char *mode)
{
    strcpy(m_filename, fileName);
    strcpy(m_mode, mode);
}

InfoMsg::~InfoMsg(void)
{
}

//get current time by type YYYY-MM-DD W HH:MM::SS
char *InfoMsg::getCurrentTime(char *timebuf)
{
	if(!timebuf) //return NULL if it did not allocate memory for timebuf;
		return NULL;
	time_t timer = time(NULL); //get current time
	struct tm *timerptr = localtime(&timer); //convert time_t to struct tm
	if(!strftime(timebuf,32,"%Y-%m-%d %a %H:%M:%S",timerptr))
		return NULL;
	return timebuf;
}

/*clear file*/
bool InfoMsg::infoClearFile(const char *filename)
{
	FILE *file = fopen(filename,"w");
	if(!file)
	{
		return false;
	}
	fclose(file);
	return true;
}

/*record errors*/
bool InfoMsg::info_error(const char *format,...)
{
	FILE *error = fopen(m_errorFileName,m_errormode);
	if(!error)
		return false;
	va_list ap;
	va_start(ap,format);
	vfprintf(error,format,ap);
	va_end(ap);
	fclose(error);
	return true;
}

/*record the logs*/
bool InfoMsg::info_log(const char *format,...)
{
	FILE *log = fopen(m_logfilename,m_logmode);
	if(log == NULL)
		return false;
	va_list ap;
	va_start(ap,format);
	vfprintf(log,format,ap);
	va_end(ap);
	fclose(log);
	return true;
}

/*write text into file */
bool InfoMsg::info(FILE *file,const char *format,...)
{
	if(file == NULL)
		return false;
	va_list ap;
	va_start(ap,format);
	vfprintf(file,format,ap);
	va_end(ap);
	return true;
}

bool InfoMsg::info_write(const char *format, ...)
{
    FILE *file = fopen(m_filename,m_mode);
    if(file == NULL)
        return false;
    va_list ap;
    va_start(ap,format);
    vfprintf(file,format,ap);
    va_end(ap);
    fclose(file);
    return true;
}

/*read data from stream*/
void InfoMsg::info_read(FILE *file,const char *format,...)
{
	if(!file)
		return ;
	va_list ap;
	va_start(ap,format);
	fscanf(file,format,ap);
	va_end(ap);
}

/* test function */
char *InfoMsg::testptr(char *buf)
{
	char *str = "world";
	strcpy(buf,str);
	//buf[5] = '\0';
	return buf;
}