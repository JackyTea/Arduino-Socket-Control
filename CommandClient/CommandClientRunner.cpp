/*
	Arduino Socket Controller
	Jacky Tea
	01/09/19
	CommandClientRunner.cpp

	Execute CommandClient class to take in user
	inputted commands to be sent to the CommandServer
	class server for further parsing and feedback.
*/

#include "CommandClient.h"

using namespace std;

int main(int argc, char * argv[]) {
	CommandClient client(27000, "127.0.0.1");
	client.startClient();

	char dataBuffer[128] = {};

	while (true) {
		cout << "Enter a color (type \"quit\" to exit): ";
		cin >> dataBuffer;

		client.sendData(dataBuffer, sizeof(dataBuffer));
	
		if (strcmp(dataBuffer, "quit") == 0) {
			break;
		}
	}

	return 0;
}