## SampleParam

This is an enhancement of the secureSampleStayAlive Task, with the possiblity to easily reconnect to another server or change the connection / SSL paramaters.

### Parameters

The sample is named "Param" because of the rather huge parameter structure that is passed to the sample thread. The Param structure is a local structure, defined in the C code,

	_LOCAL param_typ Param;

Which means you need to activate Declaration of _LOCAL _GLOBAL Variables in 
**Project -> Properties -> ANSI C/C++ Compliance**

Theres a **loadTestCase** variable that intializes some test setups

1. connect on port 1883 with 200ms refresh
2. connect on port 8883 (SSL) with login user/user and 200ms refresh
3. connect on port 8883 (SSL) with login user, and certificates and 200ms refresh
4. connect on port 8883 (SSL) with login user, and a root certificate and 200ms refresh

Anyways, the idea is that you can select some things like ssl, login, reliable and so on, then the actual connection and SSL parameters are initialized once you activate the main thread with PahoMQTT_Cyclic.Resume, **-or-** which is the best thing about this sample, if you set **Param.reset**.

In order to figure out exactly what is initialized to what, have a look at Param.c

	void param_init(param_typ* param)

### Multiple instances ###

This Task can be used for several client instances, by assigning the same code to the CPU several times. For multiple clients to work, the PahoMQTT needs to run as a static library, described in the top-level README.

In case you want to connect to the same broker on the same port (which is totally possible), you just need to make sure every Task instance uses another client name. Easiest way out is to write

	ST_name(0, Param.clientname, 0);

With that, the MQTT gets the name of the task in the Software configuration, which is unique.





