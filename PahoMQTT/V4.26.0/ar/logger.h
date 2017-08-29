#ifndef _ARLOGGER_H_
#define _ARLOGGER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*Public API*/
void ArPahoLoggerResetError();
char ArPahoLoggerGetError();
unsigned long ArPahoLoggerGetErrorCounter();
unsigned long ArPahoLoggerInit();

void ArPahoLogError(const char *format, ...);
void ArPahoLogWarning(const char *format, ...);
void ArPahoLogInfo(const char *format, ...);
void ArPahoLogSuccess(const char *format, ...);

/*Internal functions*/
void ArPahoLoggerSetLogLevel(unsigned char Level);
void ArPahoLoggerSuccess(const char *logtext);
void ArPahoLoggerInfo(const char *logtext);
void ArPahoLoggerWarning(const char *logtext);
void ArPahoLoggerError(const char *logtext);

#ifdef __cplusplus
}
#endif

#endif
