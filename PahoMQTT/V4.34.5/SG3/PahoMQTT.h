/* Automation Studio generated header file */
/* Do not edit ! */
/* PahoMQTT 4.34.5 */

#ifndef _PAHOMQTT_
#define _PAHOMQTT_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _PahoMQTT_VERSION
#define _PahoMQTT_VERSION 4.34.5
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
typedef struct PahoMQTTIntern_typ
{	unsigned long TaskIdent;
	plcbit isAlive;
	plcbit isRunning;
} PahoMQTTIntern_typ;

typedef struct PahoMQTT_Cyclic
{
	/* VAR_INPUT (analog) */
	unsigned long TaskHandle;
	unsigned char LoggerLevel;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	/* VAR (analog) */
	unsigned char _LoggerLevel;
	/* VAR_INPUT (digital) */
	plcbit Resume;
	plcbit Suspend;
	/* VAR_OUTPUT (digital) */
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
	unsigned long TaskHandle;
	plcstring ErrorInfo[81];
	unsigned short Status;
	/* VAR (analog) */
	struct PahoMQTTIntern_typ _internal;
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
_BUR_PUBLIC plcbit PahoMQTT_Exit(unsigned long TaskHandle);
_BUR_PUBLIC plcbit PahoMQTT_Sleep(unsigned long Milliseconds);
_BUR_PUBLIC plcbit PahoMQTT_IsAlive(unsigned long TaskHandle);


#ifdef __cplusplus
};
#endif
#endif /* _PAHOMQTT_ */

