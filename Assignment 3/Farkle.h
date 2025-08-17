#ifndef FARKLE_H
#define FARKLE_H
#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"
//#include "Driver.h"
using namespace std;
class Farkle:public Player
{
private:
	int targetScore = 5000;
	int intInput;
	char charInput;
	vector <Player>vPlayer;
public:
	Farkle();
	~Farkle();
	void displayTitle();
	void waitForPlayer();
	void playFarkle();
	void gameOver();
	char askForLetter(string question);
	int askForInt(string question);
	bool checkGameOver();
	void quitGame();
	void setTargetScore();
	void mainMenu();
	void resetGame();
};
#endif