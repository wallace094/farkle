#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Die.h"
using namespace std;
class Player:public Die
{
private:
	string playerName;
	int runningScore;
	char charInput;
	bool reroll;
	bool farkle;
	vector <Die> vDice;
	vector <int> vKeptDice;
protected:
	int playerScore;
	int minimumBank;
	int farkleCount; //not used
public:
	Player();
	~Player();
	string getPlayerName();
	int getPlayerScore();
	void setPlayer();
	char askForChar(string question);
	void updateScore();
	void displayInfo();
	void addDice();
	void rerollDice();
	void keepDie();
	void checkMeld();
	void checkFarkle();
	void createDiceArt();
	void bank();
	void playerTurn();
	void displayRule(string ruleFile);
	void waitForPlayer();
	void checkDieCount();
	void farkleDisplay();
	void winGameDisplay();
};
#endif