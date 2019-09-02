/*
	Arduino Socket Controller
	Jacky Tea
	01/09/19
	SerialCommunications.cpp

	SerialCommunications class designed to transmit
	user-inputted commands to a microcontroller via
	the serial port and to collect any outputted
	information (eg. error messages, measured values, etc...)
*/

#include "SerialCommunications.h"

using namespace std;
using namespace System;
using namespace System::IO::Ports;

namespace RemoteSerialController {
	//constructor
	SerialCommunications::SerialCommunications(int baudRate, System::String ^ portName) : baudRate(baudRate), portName(portName), serialPort(portName, baudRate) {}

	//destructor
	SerialCommunications::~SerialCommunications() {
		if (serialPort.IsOpen) {
			serialPort.Close();
		}
	}

	//open serial port
	void SerialCommunications::openSerialPort() {
		serialPort.Open();
	}

	//close serial port
	void SerialCommunications::closeSerialPort() {
		serialPort.Close();
	}

	//send command
	void SerialCommunications::sendCommand(int commandCode) {
		if (commandCode == 1) {
			serialPort.Write("r");
		}
		else if (commandCode == 2) {
			serialPort.Write("y");
		}
		else if (commandCode == 3) {
			serialPort.Write("g");
		}
		else if (commandCode == 4) {
			serialPort.Write("b");
		}
	}

	//receive data
	string SerialCommunications::receiveData() {
		return ""; //TODO ...
	}
}