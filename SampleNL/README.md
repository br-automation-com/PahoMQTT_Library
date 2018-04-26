## SampleNL

This is an enhancement of the Sample Task by @JobFranken where you can choose between four different threads

	void sample(unsigned long param);
	void secureSample(unsigned long param);
	void secureSampleTestServer(unsigned long param);
	void secureSampleStayAlive(unsigned long param);

You select the which thread to run via the <code>ProgramInit</code>, for example

	PahoMQTT_Init_0.MainThread = (UDINT)secureSampleTestServer;

Some short information:

### sample
This is equivalent to the [Sample](/Sample/) task, just publishing a "hello world" message. This one currently doesnt handle a lost connection.

### secureSample
Here we have added SSL to the connection to a local broker. This one currently doesnt handle a lost connection.

### secureSampleStayAlive
Same as above, but the client reconnects at a lost connection.

### secureSampleTestServer
Pretty much the same as the secureSampleStayAlive, but the connection is made to test.mosquitto.org instead. This is a useful test server and can be reached when the system is connected to the internet and DNS service is activated on the Controller.




