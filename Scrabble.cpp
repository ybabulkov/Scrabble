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
* <main cpp file>
*
*/
#include<iostream>
#include<fstream>
#include<iomanip>  
#include"game_manager.h"


int main() {
	short int choice;
	short int numOfLetters;
	short int numOfRounds;

	settings::loadSettings(numOfLetters, numOfRounds);

	std::cout << std::setw(24) << "WELCOME TO SCRABBLE!\n";
	while (true) {
		menu::printMenu();
		choice = menu::choiceInput();

		switch (choice) {
		case 1:
			game::gameLoop();
			break;
		case 2:
			settings::showSettings(numOfLetters, numOfRounds);
			settings::loadSettings(numOfLetters, numOfRounds);
			break;
		case 3:
			menu::addNewWord();
			break;
		case 4:
			menu::showAchievements();
			break;
		case 5:
			std::cout << "Exiting game...";
			return 0;
		}
	}	
}

