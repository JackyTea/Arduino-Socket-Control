/*
	Remote Serial Controller
	Jacky Tea
	00/00/00
	CommandServerRunner.cpp

	Execute CommandServer class to listen for commands
	that can be sent to SerialCommunications class for
	processing and controlling the microcontroller.
*/


#include "CommandServer.h"
#include "SerialCommunications.h"

using namespace std;
using namespace RemoteSerialController;

int main(int argc, char * argv[]) {
	CommandServer server(27000);
	server.startServer();

	SerialCommunications serialPort(9600, "COM3");
	serialPort.openSerialPort();

	char dataBuffer[128] = {};

	while (true) {
		memcpy(dataBuffer, server.receiveData(), 128);

		cout << "Command received: " << dataBuffer << endl;
		if (strcmp(dataBuffer, "red") == 0) {
			serialPort.sendCommand(1);
		}
		else if (strcmp(dataBuffer, "yellow") == 0) {
			serialPort.sendCommand(2);
		}
		else if (strcmp(dataBuffer, "green") == 0) {
			serialPort.sendCommand(3);
		}
		else if (strcmp(dataBuffer, "blue") == 0) {
			serialPort.sendCommand(4);
		}
		else if (strcmp(dataBuffer, "quit") == 0) {
			server.closeConnection();
			break;
		}
	}

	return 0;
}