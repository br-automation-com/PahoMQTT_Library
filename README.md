# PahoMQTT_Library
Eclipse Paho MQTT Client Library for B&amp;R SG4 targets

## Version Information
This is a compiled library for B&R SG4 Targets using
[https://github.com/eclipse/paho.mqtt.c](https://github.com/eclipse/paho.mqtt.c), Release version 1.2.0

Versions / AR Support:

- V4.26.x: Automation Runtime 4.26 
- v4.34.x; Automation Runtime 4.34, thanks to @JobFranken

It has been tested on following hardware / runtime:

 - CP1586 / D4.26
 - CP1586 / E4.34
 - CP0484 / E4.34
 
## Prerequisites

To get started with Paho MQTT, please visit http://www.eclipse.org/paho/

For the B&amp;R Platform, you basically need

- A MQTT broker on another system, like mosquitto
- certficates (if desired)
- The PahoMQTT Library

## Preparations

If you are using certificates for a secure connection, you make them avialable for your Controller under the filedevice "CERTS". Easiest way to do this, is to copy the folder with the certificates to the USER partition, and create a FileDevice "CERTS" under "F:\". Further, if you are accessing a host name rather than an IP-address, you need to enable the DNS service in the controller.

#### Create a CERTS file device
![](img/file_device.PNG)

#### Enable DNS Service
![](img/enable_dns.PNG)


## Getting Started

Now the system is configured to the extent that you can insert the PahoMQTT Library and start creating your application. The PahoMQTT libary should be inserted as an Exisiting Libary under the Logical view, and then you insert the sample task(s) as Existing programs.

#### Insert the PahoMQTT Library

![](img/add_lib.PNG)

The Version of the Library reflects the Runtime version it is compiled for, in this case, AR4.34.

The Library has dependencies to other B&R Libraries, that will be inserted automatically.

#### Automatically Inserted Libraries
![](img/libs.PNG)

All headerfiles you need are part of the PahoMQTT Library, so you just need to setup the compiler to include these files in the build. This can be done on a global level (as in the picture) or on a task-local level.

#### Headerfiles of PahoMQTT

![](img/headers.PNG)

#### Setup the Include directory for the Headers

![](img/compiler.PNG)

Now you are ready to create your MQTT application task. 

## Using the Library

In order to get started, insert one of the Sample tasks available here.

- [Sample](Sample/README.md) : Very simple example, publishing a hello world message
- [SampleNL](SampleNL/README.md) : Some more samples, with reconnecting at interruption, and SSL communication 
- [SampleMultiBroker](SampleMultiBroker/README.md) : Example for starting up two clients connecting to two different brokers

You select the folder as an existing program, basically starting up your client thread

![](img/add_prog.PNG)

	void sample(unsigned long param); //the Paho sample thread
	
	void _INIT ProgramInit(void)
	{		
		PahoMQTT_Init_0.EnableLogger = 1;
		PahoMQTT_Init_0.MainThread = (UDINT)sample;
		PahoMQTT_Init_0.ThreadParam = (UDINT)Message;
		PahoMQTT_Init_0.SuspendThread = 1;
		PahoMQTT_Init(&PahoMQTT_Init_0);
		
	}

The sample itself needs to run as an asynchronous thread, which the Library has already taken into consideration. You therefore pass the function pointer to the sample program to the <code>MainThread</code> Input. If you want, you can also pass other arguments, such as a structure pointer using the <code>MainParam</code> input.

In case you are going to run multiple MQTT client instances, you need to set the <code>ThreadName</code> to some unique name for each main thread you use. If you leave <code>ThreadName</code> unset, the main thread will run under the name "PahoMQTT_Main".

	strncpy(PahoMQTT_Init_0.ThreadName, "MainNL", sizeof(PahoMQTT_Init_0.ThreadName)-1);

If the sample task starts suspended using the <code>PahoMQTT_Init_0.SuspendThread</code>, you need to start the thread using the <code>PahoMQTT_Cyclic_0.Resume</code> input. The PahoMQTT_Exit is used to shutdown the AWS sample task and kill the thread when the program is redownloaded.

	void _CYCLIC ProgramCyclic(void)
	{
		PahoMQTT_Cyclic(&PahoMQTT_Cyclic_0);
	}
	
	void _EXIT ProgramExit(void)
	{
		PahoMQTT_Exit();
	}

In this case the Logger is enabled using <code>PahoMQTT_Init_0.EnableLogger</code>, you can control which level of logmessages you want to have in the logger using <code>PahoMQTT_Cyclic_0.LoggerLevel</code>.

When you have come this far, you should see the result in the Logger.
![](img/logger.PNG)

