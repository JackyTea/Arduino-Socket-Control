/*
	Arduino Socket Controller
	Jacky Tea
	01/09/19
	SerialCommunications.h

	SerialCommunications class designed to transmit
	user-inputted commands to a microcontroller via
	the serial port and to collect any outputted
	information (eg. error messages, measured values, etc...)
*/

#using <System.dll>
#include <iostream>
#include <string>

#ifndef SERIALCOMMUNICATIONS_H

namespace RemoteSerialController {

	//Serial Communications Class
	ref class SerialCommunications {
		int baudRate;
		System::String ^ portName;
		System::IO::Ports::SerialPort serialPort;
	public:
		//constructor
		SerialCommunications(int baudRate, System::String ^ portName);

		//destructor
		~SerialCommunications();

		//open serial port
		void openSerialPort();

		//close serial port
		void closeSerialPort();

		//send command
		void sendCommand(int commandCode);

		//receive data
		std::string receiveData();
	};
}

#endif // !SERIALCOMMUNICATIONS_H#pragma once
