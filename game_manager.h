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
// file manager
namespace filemanager {
	void loadSettings(short int& numOfLetters, short int& numOfRounds);
	void saveSettings(short int numOfLetters, short int numOfRounds);
}

//menu manager
namespace menu {
	void printMenu();
	void showSettings(short int numOfLetters, short int numOfRounds);
	void adjustSettings();
}


#endif
