// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
// Constant Variables
const char Rock = 'r';
const char Paper = 'p';
const char Scissors = 's';

using namespace std;

char GetComputerOption() {
	srand(time(0));
	// random number
	int num = rand() % 3 + 1;
	if (num == 1) return 'r';
	if (num == 2)return 'p';
	if (num == 3)return 's';
}
char GetUserOption() {
	char c;
	cout << "Rock,Paper,Scissors Game!" << endl;
	cout << "Please press one of the following options" << endl;
	cout << "------------------------------------------" << endl;
	cout << "(r) for rock" << endl << "(p) for paper" << endl << "(s) for scissors" << endl;
	cin >> c;

	while (c != 'r' && c != 'p' && c != 's') {
		cout << "Invalid Input, Please use the following options only." << endl;
		cout << "(r) for rock" << endl << "(p) for paper" << endl << "(s) for scissors" << endl;
		cin >> c;
	}
	return c;
}
void ShowSelectedOption(char option) {
	if (option == 'r') cout << "Rock." << endl;
	if (option == 'p') cout << "Paper." << endl;
	if (option == 's') cout << "Scissors" << endl;
}

void ChooseWinner(char uChoice, char cChoice) {
	if (uChoice == Rock && cChoice == Paper) {
		cout << "Computer Wins, Paper wraps rock" << endl;
	}
	else if (uChoice == Paper && cChoice == Scissors) {
		cout << "Computer Wins, Scissors cuts Paper" << endl;
	}
	else if (uChoice == Scissors && cChoice == Rock) {
		cout << "Computer Wins, Rock smashes Scissors" << endl;
	}
	else if (uChoice == Rock && cChoice == Scissors) {
		cout << "User Wins, Rock smashes Scissors" << endl;
	}
	else if (uChoice == Paper && cChoice == Rock) {
		cout << "User Wins, Paper covers Rock" << endl;
	}
	else if (uChoice == Scissors && cChoice == Paper) {
		cout << "User Wins, Scissors cuts Paper" << endl;
	}
	else {
		cout << "Tie, Play Again to Win the Game!" << endl;
	}

}
int main() {

	bool ContinuePlaying = true;

	while (ContinuePlaying) {


		// User Choice
		char uChoice;
		// Computer Choice
		char cChoice;


		uChoice = GetUserOption();
		cout << "Your Choice is " << endl;
		ShowSelectedOption(uChoice);

		cout << "Computer choice is " << endl;
		cChoice = GetComputerOption();
		ShowSelectedOption(cChoice);

		ChooseWinner(uChoice, cChoice);
	

		cout << "------------------------------------" << endl;
		cout << "Would you like to play again? (y/n)" << endl;

		string PlayAgain;
		cin >> PlayAgain;

		if (PlayAgain == "y") {
			uChoice = GetUserOption();
			cout << "Your Choice is " << endl;
			ShowSelectedOption(uChoice);

			cout << "Computer choice is " << endl;
			cChoice = GetComputerOption();
			ShowSelectedOption(cChoice);

			ChooseWinner(uChoice, cChoice);
		}
		else if (PlayAgain == "n") {
			cout << "Thank You for Playing" << endl;
			break;

		}
		

	}
	


	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
