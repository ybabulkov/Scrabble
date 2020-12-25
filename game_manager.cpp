/**
*
* Solution to course project # 8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yoan Babulkov
* @idnumber 62601
* @compiler VC
*
* <cpp file with helper functions>
*
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include"game_manager.h"

// file manager
namespace filemanager {

	void loadSettings(short int& numOfLetters, short int& numOfRounds) {

		std::ifstream settingsFile;
		settingsFile.open("settings.txt");
		// function from the header file under the file manager namespace
		settingsFile >> numOfLetters;
		settingsFile >> numOfRounds;

		settingsFile.close();
	}

	void saveSettings(short int numOfLetters, short int numOfRounds) {
		std::ofstream settingsFile("settings.txt");
		settingsFile << numOfLetters << std::endl;
		settingsFile << numOfRounds;
		settingsFile.close();
	}
}

//menu manager
namespace menu {
	void printMenu() {
		std::cout << std::setw(24) << "WELCOME TO SCRABBLE!\n\n";
		std::cout << "1.START GAME.  3.ADD NEW WORD.\n2.SETTINGS.    4.EXIT.\n";
	}

	void adjustSettings() {
		short int settingsChoice;
		short int numOfLetters;
		short int numOfRounds;
		bool adjusting = true;

		filemanager::loadSettings(numOfLetters, numOfRounds);

		while (adjusting) {

			std::cout << "\n1. CHANGE THE NUMBER OF LETTERS.\n";
			std::cout << "2. CHANGE THE NUMBER OF ROUNDS.\n";
			std::cout << "3. BACK TO MENU.\n";

			std::cin >> settingsChoice;
			// validity check
			if (settingsChoice < 1 || settingsChoice > 3) {
				do {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "INVALID INPUT! PLEASE SELECT BETWEEEN OPTIONS 1 and 3!\n";
					std::cin >> settingsChoice;
				} while (settingsChoice < 1 || settingsChoice > 3);
			}
			if (settingsChoice == 1) {
				std::cout << "\nENTER THE NUMBER OF LETTERS: ";
				std::cin >> numOfLetters;
			}
			else if (settingsChoice == 2) {
				std::cout << "ENTER THE NUMBER OF ROUNDS: ";
				std::cin >> numOfRounds;
			}
			else {
				adjusting = false;
			}
		}
		filemanager::saveSettings(numOfLetters, numOfRounds);
	}
}

