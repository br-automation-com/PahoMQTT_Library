
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif
void sample(unsigned long param);

void _INIT ProgramInit(void)
{		
	PahoMQTT_Init_0.EnableLogger = 1;
	PahoMQTT_Init_0.MainThread = (UDINT)sample;
	PahoMQTT_Init_0.ThreadParam = (UDINT)Message;
	PahoMQTT_Init_0.SuspendThread = 1;
	PahoMQTT_Init(&PahoMQTT_Init_0);
}

void _CYCLIC ProgramCyclic(void)
{
	PahoMQTT_Cyclic(&PahoMQTT_Cyclic_0);
}

void _EXIT ProgramExit(void)
{
	PahoMQTT_Exit();
}

