#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include <stdlib.h>
#include <string.h>
#include <PahoMQTT.h>
#include "MQTTClient.h"
#include "ar/logger.h"

#define ADDRESS     "ssl://192.168.0.240:8883"
#define CLIENTID    "SubSample"
#define TOPIC       "test"
#define PAYLOAD     message
#define QOS         1
#define TIMEOUT     10000L

void secureSampleSubscribe(unsigned long param)
{
	do
	{
	    MQTTClient client;
	    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
	    MQTTClient_message pubmsg = MQTTClient_message_initializer;
	    MQTTClient_deliveryToken token;
	    MQTTClient_SSLOptions ssl_opts = MQTTClient_SSLOptions_initializer;
	    int rc = 0;
	    
	    rc = MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
	    
	    conn_opts.keepAliveInterval = 20;
	    conn_opts.reliable = 0;
	    conn_opts.cleansession = 1;
	    ssl_opts.enableServerCertAuth = 0;
	       
	    conn_opts.ssl = &ssl_opts;
	    
	    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
	    {
	        ArPahoLogError("Failed to connect, return code %d\n", rc);
	    }
	    else
	    {
			
			char topicName[20] = "";
			int topicLength ;
			MQTTClient_message * recvMessage  ;
			
			// subscribe
			MQTTClient_subscribe  ( client ,  TOPIC , 0 );  
					
	        while(PahoMQTT_IsAlive())
	        {
				MQTTClient_receive  ( client,  &topicName,  &topicLength ,  &recvMessage ,  10  ) ;
	    
				if( topicName > 0 )
				{
					ArPahoLogSuccess("Recieved Topic %s with message %s \n", topicName, recvMessage->payload);
					
					MQTTClient_freeMessage  ( &recvMessage ) ;
				}		
			
	            PahoMQTT_Sleep(5000);
	        }
	    }
	    MQTTClient_disconnect(client, 10000);
	    MQTTClient_destroy(&client);
		
	} while(PahoMQTT_IsReset());
}
