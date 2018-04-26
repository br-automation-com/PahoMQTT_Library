
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif
void sample(unsigned long param);
void secureSample(unsigned long param);
void secureSampleTestServer(unsigned long param);
void secureSampleStayAlive(unsigned long param);

void _INIT ProgramInit(void)
{		

	PahoMQTT_Init_0.EnableLogger = 1;
	PahoMQTT_Init_0.MainThread = (UDINT)secureSampleTestServer;
		//    PahoMQTT_Init_0.MainThread = (UDINT)sample;
	PahoMQTT_Init_0.ThreadParam = (UDINT)Message;
	PahoMQTT_Init_0.SuspendThread = 1;
	strncpy(PahoMQTT_Init_0.ThreadName, "MainNL", sizeof(PahoMQTT_Init_0.ThreadName)-1);
	
	PahoMQTT_Init(&PahoMQTT_Init_0);
	taskHandle1 = PahoMQTT_Init_0.TaskHandle;
	PahoMQTT_Cyclic_0.LoggerLevel = 4;
}

void _CYCLIC ProgramCyclic(void)
{
	PahoMQTT_Cyclic_0.TaskHandle = PahoMQTT_Init_0.TaskHandle;
	PahoMQTT_Cyclic(&PahoMQTT_Cyclic_0);
}

void _EXIT ProgramExit(void)
{
	PahoMQTT_Exit(PahoMQTT_Init_0.TaskHandle);
}

