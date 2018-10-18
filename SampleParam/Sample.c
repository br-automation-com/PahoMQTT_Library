#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

#include <stdlib.h>
#include <string.h>
#include <PahoMQTT.h>
#include "MQTTClient.h"
#include "ar/logger.h"
#include "Param.h"

#define ADDRESS     param->url
#define CLIENTID    param->clientname
#define TOPIC       param->topic
#define PAYLOAD     param->message
#define QOS         1
#define TIMEOUT     param->timeout

void sample(unsigned long param_adr)
{
	param_typ *param = (param_typ *)param_adr;
	
	do
	{
		param->restart = 0;
		param->cycles = 0;
		param_init(param);
		
		MQTTClient client;
		MQTTClient_message pubmsg = MQTTClient_message_initializer;
		MQTTClient_deliveryToken token;
		
		int rc;
		MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
		   
		while(PahoMQTT_IsAlive() && !param->restart)
		{
		   
			if ((rc = MQTTClient_connect(client, &param->conn_opts)) != MQTTCLIENT_SUCCESS)
			{
				ArPahoLogError("Failed to connect, return code %d\n", rc);
				PahoMQTT_Sleep(TIMEOUT);
			}
			else
			{
				while(MQTTClient_isConnected(client) && PahoMQTT_IsAlive() && !param->restart)
				{
					pubmsg.payload      = PAYLOAD;
					pubmsg.payloadlen   = strlen(PAYLOAD);
					pubmsg.qos          = QOS;
					pubmsg.retained     = 0;
					MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
					ArPahoLogInfo("Waiting for up to %d seconds for publication of %s\n"
						"on topic %s for client with ClientID: %s\n",
						(int)(TIMEOUT/1000), PAYLOAD, TOPIC, CLIENTID);
					rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
					ArPahoLogSuccess("Message with delivery token %d delivered\n", token);
			
					param->cycles++;
					PahoMQTT_Sleep(param->sleep);
				}
			}
		}
		MQTTClient_disconnect(client, TIMEOUT);
		MQTTClient_destroy(&client);
	} while(param->restart);
}
