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
#include<string>
#include<fstream> 
#include<time.h>
#include<stdlib.h>
#include<string>
#include"game_manager.h"

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

// file manager
namespace settings {

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

	void showSettings(short int numOfLetters, short int numOfRounds) {
		std::cout << "\nCurrent number of letters: " << numOfLetters << std::endl;
		std::cout << "Current number of rounds: " << numOfRounds << std::endl;
	}

	void adjustSettings() {
		short int settingsChoice;
		short int numOfLetters;
		short int numOfRounds;
		bool adjusting = true;

		settings::loadSettings(numOfLetters, numOfRounds);

		while (adjusting) {

			std::cout << "\n1. Change the number of letters.\n";
			std::cout << "2. Change the number of rounds.\n";
			std::cout << "3. Back to menu.\n";

			std::cin >> settingsChoice;
			// validity check
			if (settingsChoice < 1 || settingsChoice > 3) {
				do {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input! please select betweeen options 1 and 3!\n";
					std::cin >> settingsChoice;
				} while (settingsChoice < 1 || settingsChoice > 3);
			}
			if (settingsChoice == 1) {
				std::cout << "\nEnter the number of letters: ";
				std::cin >> numOfLetters;
			}
			else if (settingsChoice == 2) {
				std::cout << "Enter the number of rounds: ";
				std::cin >> numOfRounds;
			}
			else {
				adjusting = false;
			}
		}
		settings::saveSettings(numOfLetters, numOfRounds);
	}
}

//menu manager
namespace menu {
	void printMenu() {
		std::cout << "\n1.START GAME.  3.ADD NEW WORD.\n2.SETTINGS.    4.EXIT.\n";
	}
	
	void addNewWord() {
		
		std::string newWord;
		bool addingWords = true;
		while (addingWords) {
			std::cout << "Please add a word or type 'e' to return to the main menu: ";
			std::cin >> newWord;
			if (newWord == "e" || newWord == "E") {
				break;
			}
			if (!isInDictionary(newWord)) {
				std::ofstream dictFile;
				dictFile.open("words.txt", std::ios::app);
				dictFile << std::endl << newWord;
				dictFile.close();
				std::cout << newWord << " has successfully been added to the dictionary\n";
			}
			else {
				std::cout << "This word is already in the dictionary!\n";
			}
		}
	}
}

namespace game {
	void showLetters(std::string letters) {
		for (int i = 0; i < letters.size(); i++) {
			std::cout << letters[i] << " ";
		}
		std::cout << std::endl;
	}

	bool lengthExceeds(std::string input, std::string letters) {
		return (input.size() > letters.size() ? true : false);
	}

	void validateInput(std::string& input, std::string letters) {
		bool foundLetter = false;
		bool validInput = false;
		std::string originalLetters = letters;
	
		while (!validInput) {
			while (lengthExceeds(input, letters)) {
				std::cout << "The length of the word exceeds the number of letters given!\n";
				std::cin >> input;
			}
			letters = originalLetters;
			for (int i = 0; i < input.size(); i++) {
				foundLetter = false;
				for (int j = 0; j < letters.size(); j++) {
					if (input[i] == letters[j]) {
						foundLetter = true;
						letters.erase(letters.begin() + j);
						break;
					}
				}
				if (!foundLetter) {
					validInput = false;
					std::cout << "Invalid word. Try again with: ";
					showLetters(originalLetters);
					std::cin >> input;
					break;
				}
				else {
					validInput = true;
				}
			}
		}	
	}

	int countVowels(std::string letters) {
		int vowelCount = 0;
		char vowels[7] = "aeiouy";
		for (int i = 0; i < letters.size(); i++) {
			for (int j = 0; j < sizeof(vowels); j++) {
				if (letters[i] == vowels[j]) {
					vowelCount++;
				}
			}
		}
		return vowelCount;
	}

	std::string generateLetters(int numLetters) {
		const int MIN_NUMBER_VOWELS = numLetters / 3 + 1;
		std::string letters = "";
		do {
			letters.clear();
			for (int i = 0; i < numLetters; i++) {
				char letter = char(rand() % 25 + 97);
				letters.push_back(letter);
			}
		} while (countVowels(letters) < MIN_NUMBER_VOWELS);
		return letters;
	}

	void gameLoop() {
		short int points = 0;
		short int numLetters, numRounds;
		settings::loadSettings(numLetters, numRounds);

		std::string playerInput;
		std::srand(time(0));

		short int round = 1;
		while (round <= numRounds) {
			std::string letters = generateLetters(numLetters);
			std::cout << "Round " << round << ". Available letters: ";
			showLetters(letters);

			std::cin >> playerInput;
			validateInput(playerInput, letters);

			while (!isInDictionary(playerInput)) {
				std::cout << "Word not found in Dictionary! Try again with: ";
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

