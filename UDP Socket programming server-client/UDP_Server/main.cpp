#include "Server.h"
#include "Client.h"
#include <iostream>
#include <windows.h>
#include <thread>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1" // localhost

enum class ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    LightYellow = 14,
    BrightWhite = 15
};

void setColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
}

void resetColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7); // White
}

int main(void) {
	Server server(SERVER_PORT);
	Client client(SERVER_IP, SERVER_PORT);
	
    std::thread serverThread([&]() {
        server.run();
    });

	for (;;) {
        setColor(ConsoleColor::Gray);
		std::string input; std::cout << "\nEnter command: "; 
        resetColor();
		std::getline(std::cin, input);

		client.send(input);
		std::string reply = client.receiveMessage();
        setColor(ConsoleColor::Green);
		std::cout << "\nServer reply: " << reply << std::endl;
        resetColor();
        if (input == "/exit") { break; }
	}
    serverThread.join();
	return 0;
}