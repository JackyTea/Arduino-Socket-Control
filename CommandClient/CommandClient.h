/*
	Arduino Socket Controller
	Jacky Tea
	01/09/19
	CommandClient.h

	CommandClient class designed to trasmit user commands
	to a CommandServer class for further processing and
	receive information back on errors and analytics.
*/

#include <windows.networking.sockets.h>
#include <iostream>
#include <string>
#pragma comment(lib, "Ws2_32.lib")

#ifndef COMMANDCLIENT_H

//Command Client Class
class CommandClient {
	int portNumber;
	std::string ipAddress;
	char dataBuffer[128];
	WSADATA wsaData;
	SOCKET clientSocket;
	sockaddr_in serverAddress;
public:
	//constructor
	CommandClient(int portNumber, std::string ipAddress);

	//destructor
	~CommandClient();

	//start client
	void startClient();

	//start Winsock DLLs
	void startDLLs();

	//setup client socket
	void setupClientSocket();

	//connect socket
	void connectSocket();

	//send data
	void sendData(const char * buffer, unsigned int size);

	//receive data
	char * receiveData();
};

#endif // !COMMANDCLIENT_H
