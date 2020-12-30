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
* <header file with helper functions>
*
*/
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

bool isInDictionary(std::string input);

// file manager
namespace settings {
	void loadSettings(short int& numOfLetters, short int& numOfRounds);
	void saveSettings(short int numOfLetters, short int numOfRounds);
	void adjustSettings();
	void showSettings(short int numOfLetters, short int numOfRounds);
}


//menu manager
namespace menu {
	void printMenu();
	void addNewWord();
}

namespace game {
	void showLetters(std::string letters);
	bool lengthExceeds(std::string input, std::string letters);
	void validateInput(std::string& input, std::string letters);
	void gameLoop();
}
#endif
