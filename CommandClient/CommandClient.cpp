/*
	Remote Serial Controller
	Jacky Tea
	00/00/00
	CommandClient.h

	CommandClient class designed to trasmit user commands
	to a CommandServer class for further processing and
	receive information back on errors and analytics.
*/

#include "CommandClient.h"

using namespace std;

//constructor
CommandClient::CommandClient(int portNumber, std::string ipAddress) : portNumber(portNumber), ipAddress(ipAddress) {}

//destructor
CommandClient::~CommandClient() {
	closesocket(clientSocket);
	WSACleanup();
	cout << "Exiting client connection on port: " << portNumber << endl;
}

//start client
void CommandClient::startClient() {
	startDLLs();
	setupClientSocket();
	connectSocket();
}

//start Winsock DLLs
void CommandClient::startDLLs() {
	if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
		cout << "ERROR! Unable to initialize Winsock DLLS!" << endl;
		exit(1);
	}
}

//setup client socket
void CommandClient::setupClientSocket() {
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		WSACleanup();
		cout << "ERROR! Unable to initialize the client socket!" << endl;
		exit(1);
	}
}

//connect socket
void CommandClient::connectSocket() {
	serverAddress.sin_family = AF_INET;						
	serverAddress.sin_port = htons(portNumber);
	serverAddress.sin_addr.s_addr = inet_addr(ipAddress.c_str());
	if ((connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress))) == SOCKET_ERROR) {
		closesocket(clientSocket);
		WSACleanup();
		cout << "ERROR! Unable to establish a connection with server!" << endl;
		exit(1);
	}
	cout << "[CLIENT] Connection successfully established on port: " << portNumber << endl;
}

//send data
void CommandClient::sendData(const char * buffer, unsigned int size) {
	send(clientSocket, buffer, size, 0);
}

//receive data
char * CommandClient::receiveData() {
	recv(clientSocket, dataBuffer, sizeof(dataBuffer), 0);
	return dataBuffer;
}