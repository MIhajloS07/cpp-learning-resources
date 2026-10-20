#pragma once
#include <WinSock2.h>
#include <string>

class Client {
	SOCKET clientSocket;
	sockaddr_in server;
	int serverLen;
public:
	Client(const std::string& serverIP, int port);
	~Client();
	void send(const std::string& message);
	std::string receiveMessage();
};

