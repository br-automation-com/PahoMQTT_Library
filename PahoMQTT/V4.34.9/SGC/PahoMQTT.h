/* Automation Studio generated header file */
/* Do not edit ! */
/* PahoMQTT 4.34.9 */

#ifndef _PAHOMQTT_
#define _PAHOMQTT_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _PahoMQTT_VERSION
#define _PahoMQTT_VERSION 4.34.9
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG4
		#include "AsIecCon.h"
		#include "AsHW.h"
		#include "AsETH.h"
		#include "FileIO.h"
		#include "AsHost.h"
		#include "ArEventLog.h"
		#include "sys_lib.h"
#endif
#ifdef _SG3
		#include "AsIecCon.h"
		#include "AsHW.h"
		#include "AsETH.h"
		#include "FileIO.h"
		#include "AsHost.h"
		#include "ArEventLog.h"
		#include "sys_lib.h"
#endif
#ifdef _SGC
		#include "AsIecCon.h"
		#include "AsHW.h"
		#include "AsETH.h"
		#include "FileIO.h"
		#include "AsHost.h"
		#include "ArEventLog.h"
		#include "sys_lib.h"
#endif

/* Datatypes and datatypes of function blocks */
typedef struct PahoMQTT_Cyclic
{
	/* VAR_INPUT (analog) */
	unsigned char LoggerLevel;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	plcstring ErrorInfo[81];
	/* VAR (analog) */
	unsigned char _LoggerLevel;
	unsigned long _inst;
	/* VAR_INPUT (digital) */
	plcbit Resume;
	plcbit Suspend;
	/* VAR_OUTPUT (digital) */
	plcbit Alive;
	plcbit Running;
	/* VAR (digital) */
	plcbit _Resume;
	plcbit _Suspend;
} PahoMQTT_Cyclic_typ;

typedef struct PahoMQTT_Init
{
	/* VAR_INPUT (analog) */
	unsigned long MainThread;
	unsigned long ThreadParam;
	plcstring ThreadName[14];
	/* VAR_OUTPUT (analog) */
	plcstring ErrorInfo[81];
	unsigned short Status;
	/* VAR_INPUT (digital) */
	plcbit EnableLogger;
	plcbit SuspendThread;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Error;
} PahoMQTT_Init_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void PahoMQTT_Cyclic(struct PahoMQTT_Cyclic* inst);
_BUR_PUBLIC void PahoMQTT_Init(struct PahoMQTT_Init* inst);
_BUR_PUBLIC plcbit PahoMQTT_Exit(void);
_BUR_PUBLIC plcbit PahoMQTT_Sleep(unsigned long Milliseconds);
_BUR_PUBLIC plcbit PahoMQTT_IsAlive(void);


#ifdef __cplusplus
};
#endif
#endif /* _PAHOMQTT_ */

