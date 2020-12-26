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
#include<random> 
#include<string>
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
	void showSettings(short int numOfLetters, short int numOfRounds) {
		std::cout << "\nCurrent number of letters: " << numOfLetters << std::endl;
		std::cout << "Current number of rounds: " << numOfRounds << std::endl;
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

namespace game {
	void showLetters(std::string letters) {
		for (int i = 0; i < letters.size(); i++) {
			std::cout << letters[i] << " ";
		}
		std::cout << std::endl;
	}

	void validateInput(std::string input, std::string letters) {
		int numLetters = letters.size();
		bool foundLetter = false;
		bool validInput = false;
		std::string originalLetters = letters;

		while (!validInput) {
			letters = originalLetters;
			for (int i = 0; i < input.size(); i++) {
				for (int j = 0; j < numLetters; j++) {
					if (input[i] == letters[j]) {
						foundLetter = true;
						letters.erase(letters.begin() + j);
						break;
					}
				}
				if (!foundLetter) {
					std::cout << "Invalid word. Try again with: ";
					showLetters(originalLetters);
					std::cin >> input;
					break;
				}
			}
			validInput = true;
		}
		
	}

	bool isInDictionary(std::string input) {
		std::string word;

		std::ifstream dict;
		dict.open("words.txt");
		while (std::getline(dict, word)) {
			if (input == word) {
				return true;
			}
		}
		return false;
	}

	void gameLoop() {
		short int points = 0;
		short int numLetters, numRounds;
		filemanager::loadSettings(numLetters, numRounds);
		
		std::random_device seed; 
		std::mt19937 gen(seed());
		std::uniform_int_distribution<int> interval(97, 122);

		std::string playerInput;

		short int round = 1;
		while (round <= numRounds) {
			std::string letters = "";
			for (int i = 0; i < numLetters; i++) {
				char letter = char(interval(gen));
				letters.push_back(letter);
			}
			std::cout << "Round " << round << ". Available letters: ";
			showLetters(letters);

			std::cin >> playerInput;
			validateInput(playerInput, letters);

			while (!isInDictionary(playerInput)) {
				std::cout << "Invalid word. Try again with: ";
				showLetters(letters);
				std::cin >> playerInput;
				validateInput(playerInput, letters);
			}
			points += playerInput.size();
			std::cout << "Good job! Your points so far are: " << points << std::endl;
			round++;
		}
		std::cout << "Your total points are " << points;
		std::cout << "\nReturning to menu...\n";
	}	
}




