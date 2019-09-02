/*
	Remote Serial Controller
	Jacky Tea
	00/00/00
	CommandServer.cpp

	CommandServer class designed to receive user commands
	tranmitted over a socket connection and direct them to
	the SerialCommunications class for further processing.
	This class utilizes the C++ Winsock library and its features.
*/

#include "CommandServer.h"

using namespace std;

//constructor
CommandServer::CommandServer(int portNumber) : portNumber(portNumber) {}

//destructor
CommandServer::~CommandServer() {
	closesocket(serverSocket);
	WSACleanup();
	cout << "Exiting server connection on port: " << portNumber << endl;
}

//start server
void CommandServer::startServer() {
	startDLLs();
	setupServerSocket();
	bindSocket();
	listenForConnection();
	acceptConnection();
}

//start Winsock DLLs
void CommandServer::startDLLs() {
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cout << "ERROR! Unable to initialize Winsock DLLS!" << endl;
		exit(1);
	}
}

//setup server socket
void CommandServer::setupServerSocket() {
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET) {
		WSACleanup();
		cout << "ERROR! Unable to initialize the server socket!" << endl;
		exit(1);
	}
}

//bind socket
void CommandServer::bindSocket() {
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(portNumber);
	if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
		closesocket(serverSocket);
		WSACleanup();
		cout << "ERROR! Unable to bind socket on port: " << portNumber << endl;
		exit(1);
	}
}

//listen for connection
void CommandServer::listenForConnection() {
	if (listen(serverSocket, 1) == SOCKET_ERROR) {
		closesocket(serverSocket);
		WSACleanup();
		cout << "ERROR! Unable to configure server socket to listening state!" << endl;
		exit(1);
	}
}

//accept client connection
void CommandServer::acceptConnection() {
	connectionSocket = SOCKET_ERROR;
	if ((connectionSocket = accept(serverSocket, NULL, NULL)) == SOCKET_ERROR) {
		closesocket(serverSocket);
		WSACleanup();
		cout << "ERROR! Unable to establish a connection with client!" << endl;
		exit(1);
	}
	cout << "[SERVER] Connection successfully established on port: " << portNumber << endl;
}

//close connection
void CommandServer::closeConnection() {
	closesocket(connectionSocket);
	cout << "Connection closed on port: " << portNumber << endl;
}

//send data
void CommandServer::sendData(const char * buffer, unsigned int size) {
	send(connectionSocket, buffer, size, 0);
}

//receive data
char * CommandServer::receiveData() {
	recv(connectionSocket, dataBuffer, sizeof(dataBuffer), 0);
	return dataBuffer;
}
