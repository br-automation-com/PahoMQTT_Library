
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif
void sample1(unsigned long param);
void sample2(unsigned long param);

void _INIT ProgramInit(void)
{		
	PahoMQTT_Cyclic_0.LoggerLevel = 4;

	PahoMQTT_Init_0.EnableLogger = 1;
	PahoMQTT_Init_0.MainThread = (UDINT)sample1;
	PahoMQTT_Init_0.ThreadParam = (UDINT)Message1;
	PahoMQTT_Init_0.SuspendThread = 1;
	strncpy(PahoMQTT_Init_0.ThreadName, "PahoMQTT_1", sizeof(PahoMQTT_Init_0.ThreadName)-1);
	PahoMQTT_Init(&PahoMQTT_Init_0);
	taskHandle1 = PahoMQTT_Init_0.TaskHandle;

	PahoMQTT_Init_1.EnableLogger = 1;
	PahoMQTT_Init_1.MainThread = (UDINT)sample2;
	PahoMQTT_Init_1.ThreadParam = (UDINT)Message2;
	PahoMQTT_Init_1.SuspendThread = 1;
	strncpy(PahoMQTT_Init_1.ThreadName, "PahoMQTT_2", sizeof(PahoMQTT_Init_1.ThreadName)-1);
	PahoMQTT_Init(&PahoMQTT_Init_1);
	taskHandle2 = PahoMQTT_Init_1.TaskHandle;
}


void _CYCLIC ProgramCyclic(void)
{
	PahoMQTT_Cyclic_0.TaskHandle = PahoMQTT_Init_0.TaskHandle;
	PahoMQTT_Cyclic(&PahoMQTT_Cyclic_0);

	PahoMQTT_Cyclic_1.TaskHandle = PahoMQTT_Init_1.TaskHandle;
	PahoMQTT_Cyclic(&PahoMQTT_Cyclic_1);

}

void _EXIT ProgramExit(void)
{
	PahoMQTT_Exit(PahoMQTT_Init_0.TaskHandle);
	PahoMQTT_Exit(PahoMQTT_Init_1.TaskHandle);
}

