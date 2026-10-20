#pragma once
#include <WinSock2.h>
#include <string>

class Server {
	SOCKET serverSocket;
	sockaddr_in server, client;
	int clientLen;
public:
	Server(int port);
	~Server();
	std::string processCommand(const std::string& command);
	std::string receiveMessage();
	void run();
	void logToFile(const std::string& entry);
	void send(const std::string& message);
};