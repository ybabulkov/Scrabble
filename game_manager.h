
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include<iostream>
#include<iomanip>

// file manager
namespace filemanager {
	void loadSettings(short int& numOfLetters, short int& numOfRounds);
}

//menu manager
namespace menu {
	void printMenu();

	void adjustSettings();
}


#endif