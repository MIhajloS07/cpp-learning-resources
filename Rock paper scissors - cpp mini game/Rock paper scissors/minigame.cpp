#include <iostream>
#include <ctime>
#include <string>
#include <algorithm> 
using namespace std;

int main() {
	bool play = true;
	string answer = "";
	string computer;
	string person;
	cout << "---------------------------------" << endl;
	cout << "Welcome to rock,paper or scissors game!" << endl;
	cout << "---------------------------------" << endl;
	while (play) {
		person = "";
		computer = "";
		cout << "ROCK,PAPER or SCISSORS ?  "; cin >> person; // person enter option (string)
		transform(person.begin(), person.end(), person.begin(), toupper); //transform string to uppercase
		while (person != "ROCK" && person != "PAPER" && person != "SCISSORS") {
			cout << "---------------------------------" << endl;
			cout << "WRONG! -> ROCK,PAPER or SCISSORS ?  "; cin >> person;
			transform(person.begin(), person.end(), person.begin(), toupper);
		}

		//generating random num between 1 and 3: 
		srand(time(0));
		switch (rand() % 3 + 1) {
		case 1:
			computer = "ROCK";
			break;
		case 2:
			computer = "PAPER";
			break;
		case 3:
			computer = "SCISSORS";
			break;
		}

		cout << endl;
		cout << "Person: " << person << endl;
		cout << "Computer: " << computer << endl;
		cout << endl;

		if (person == "ROCK") {
			if (computer == "ROCK") {
				cout << "----------------" << endl;
				cout << "DRAW!" << endl;
				cout << "----------------" << endl;
			}
			else if (computer == "PAPER") {
				cout << "----------------" << endl;
				cout << "YOU LOSE!" << endl;
				cout << "----------------" << endl;
			}
			else if (computer == "SCISSORS") {
				cout << "----------------" << endl;
				cout << "YOU WIN!" << endl;
				cout << "----------------" << endl;
			}
		}
		if (person == "PAPER") {
			if (computer == "PAPER") {
				cout << "----------------" << endl;
				cout << "DRAW!" << endl;
				cout << "----------------" << endl;
			}
			else if (computer == "SCISSORS") {
				cout << "----------------" << endl;
				cout << "YOU LOSE!" << endl;
				cout << "----------------" << endl;
			}
			else if (computer == "ROCK") {
				cout << "----------------" << endl;
				cout << "YOU WIN!" << endl;
				cout << "----------------" << endl;
			}
		}
		if (person == "SCISSORS") {
			if (computer == "SCISSORS") {
				cout << "----------------" << endl;
				cout << "DRAW!" << endl;
				cout << "----------------" << endl;
			}
			else if (computer == "ROCK") {
				cout << "----------------" << endl;
				cout << "YOU LOSE!" << endl;
				cout << "----------------" << endl;
			}
			else if (computer == "PAPER") {
				cout << "----------------" << endl;
				cout << "YOU WIN!" << endl;
				cout << "----------------" << endl;
			}
		}
		cout << "Do you want to play again(Y/N): "; cin >> answer;
		transform(answer.begin(), answer.end(), answer.begin(), toupper);
		if (answer == "Y") {
			cout << "---------------------------------" << endl;
			cout << "Thank you for playing again!" << endl;
			cout << endl;
			play = true;
		}
		if (answer == "N") {
			cout << "---------------------------------" << endl;
			cout << "Exiting game..." << endl;
			play = false;
		}
	}	
	return 0;
}