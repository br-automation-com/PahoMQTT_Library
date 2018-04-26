## SampleMultiBroker

This is a demonstrator for connnecting to several brokers, with more than one client instance. 

The noteable thing here is that the <code>CLIENTID</code> used in <code>MQTTClient_create</code> needs to be unique, as well as the ThreadName, passed in the PahoMQTT_Init function.

	strncpy(PahoMQTT_Init_0.ThreadName, "PahoMQTT_1", sizeof(PahoMQTT_Init_0.ThreadName)-1);
	strncpy(PahoMQTT_Init_1.ThreadName, "PahoMQTT_2", sizeof(PahoMQTT_Init_1.ThreadName)-1);

It uses the [Sample](/Sample/) example that publishes a "Hello world!" message every 5 seconds. Whereas the messages are contained in the <code>Message1</code> and <code>Message2</code> variable, the <code>CLIENTID</code>, the TOPIC and the IP address of the individual brokers are defined in the Sample1.c and Sample2.c files. This sample currently doesnt handle a lost connection, see some of the [SampleNL](/SampleNL/) examples for that feature.



