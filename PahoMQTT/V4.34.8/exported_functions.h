/*used for the linker
SET PATH=%PATH%;c:\BrAutomation\AS43\AS\gnuinst\V4.1.2\bin\
i386-elf-gcc -x c exported_functions.h -Os -fno-builtin -fno-leading-underscore -g -fPIC -ansi -shared -nostartfiles "-Wl,-shared,--strip-debug" -D_REPLACE_CONST -o libPahoMQTT.a

SET PATH=%PATH%;C:\BrAutomation\AS43\AS\gnuinst\V4.1.2\bin\
arm-elf-gcc -x c exported_functions.h -Os -fno-builtin -fno-leading-underscore -ggdb -fPIC -ansi -shared -nostartfiles "-Wl,-shared,--strip-debug" -D_REPLACE_CONST -o libPahoMQTT.a

*/

void MQTTClient_global_init() {}
void MQTTClient_setCallbacks() {}
void MQTTClient_create() {}
void MQTTClient_getVersionInfo() {}
void MQTTClient_connect() {}
void MQTTClient_disconnect() {}
void MQTTClient_isConnected() {}
void MQTTClient_subscribe() {}
void MQTTClient_subscribeMany() {}
void MQTTClient_unsubscribe() {}
void MQTTClient_unsubscribeMany() {}
void MQTTClient_publish() {}
void MQTTClient_publishMessage() {}
void MQTTClient_waitForCompletion() {}
void MQTTClient_getPendingDeliveryTokens() {}
void MQTTClient_yield() {}
void MQTTClient_receive() {}
void MQTTClient_freeMessage() {}
void MQTTClient_free() {}
void MQTTClient_destroy() {}
void ArPahoLogError() {}
void ArPahoLogWarning() {}
void ArPahoLogInfo() {}
void ArPahoLogSuccess() {}
void PahoMQTT_Init() {}
void PahoMQTT_Cyclic() {}
void PahoMQTT_Exit() {}
void PahoMQTT_Sleep() {}
void PahoMQTT_IsAlive() {}
