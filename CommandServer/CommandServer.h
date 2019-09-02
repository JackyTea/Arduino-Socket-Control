/*
	Remote Serial Controller
	Jacky Tea
	00/00/00
	CommandServer.h

	CommandServer class designed to receive user commands
	tranmitted over a socket connection and direct them to
	the SerialCommunications class for further processing.
	This class utilizes the C++ Winsock library and its features.
*/

#include <windows.networking.sockets.h>
#include <iostream>
#include <string>
#pragma comment(lib, "Ws2_32.lib")

#ifndef COMMANDSERVER_H

// Command Server Class
class CommandServer {
	int portNumber;
	char dataBuffer[128];
	WSADATA wsaData;
	SOCKET serverSocket, connectionSocket;
	sockaddr_in serverAddress;
public:
	//constructor
	CommandServer(int portNumber);

	//destructor
	~CommandServer();

	//start server
	void startServer();

	//start Winsock DLLs
	void startDLLs();

	//setup server socket
	void setupServerSocket();

	//bind socket
	void bindSocket();

	//listen for connection
	void listenForConnection();

	//accept client connection
	void acceptConnection();

	//close connection
	void closeConnection();

	//send data
	void sendData(const char * buffer, unsigned int size);

	//receive data
	char * receiveData();
};

#endif // !COMMANDSERVER_H