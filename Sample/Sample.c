
#include <stdlib.h>
#include <string.h>
#include <PahoMQTT.h>
#include "MQTTClient.h"
#include "ar/logger.h"

#define ADDRESS     "tcp://192.168.0.1:1883"
#define CLIENTID    "ExampleClientPub"
#define TOPIC       "MQTT Examples"
#define PAYLOAD     message
#define QOS         1
#define TIMEOUT     10000L

void sample(unsigned long param)
{
	char *message = (char *)param;

    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;
    MQTTClient_create(&client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        ArPahoLogError("Failed to connect, return code %d\n", rc);
    }
    else
	{
		while(PahoMQTT_IsAlive())
		{
			pubmsg.payload = PAYLOAD;
		    pubmsg.payloadlen = strlen(PAYLOAD);
		    pubmsg.qos = QOS;
		    pubmsg.retained = 0;
		    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
		    ArPahoLogInfo("Waiting for up to %d seconds for publication of %s\n"
		            "on topic %s for client with ClientID: %s\n",
		            (int)(TIMEOUT/1000), PAYLOAD, TOPIC, CLIENTID);
		    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
		    ArPahoLogSuccess("Message with delivery token %d delivered\n", token);
		
			PahoMQTT_Sleep(5000);
		}
    
	}
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
}
