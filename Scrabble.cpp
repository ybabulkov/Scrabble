#include<iostream>
#include<fstream>
#include"game_controller.h"

int choiceInput() {

	short int _choice;
	std::cin >> _choice;
	// validity check
	if (_choice < 1 || _choice > 4) {
		do {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "INVALID INPUT! PLEASE SELECT BETWEEEN OPTIONS 1-4!\n";
			std::cin >> _choice;
		} while (_choice < 1 || _choice > 4);
	}
	return _choice;
}

int main() {
	short int choice;
	
	short int numOfLetters;
	short int numOfRounds;

	fm::loadSettings(numOfLetters, numOfRounds);
	menu::printMenu();

	choice = choiceInput();

	switch(choice) {
		//case 1:
		//	gameLoop();
		//	break;

	case 2:
		menu::adjustSettings();
		fm::loadSettings(numOfLetters, numOfRounds);
		break;

		//case 3:
		//	addNewWord();
		//	break;

		//case 4:
		return 0;
	}
}

