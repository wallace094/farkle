#include "Player.h"


Player::Player()
{
	playerScore = 0;
	runningScore = 0;
}

Player::~Player()
{
}

string Player::getPlayerName()
{
	return playerName;
}

int Player::getPlayerScore()
{
	return playerScore;
}

void Player::setPlayer()
{
	cout << "Please Enter Your Name: ";
	cin >> playerName;
	playerScore = 0;
	runningScore = 0;
	farkle = false;
}

char Player::askForChar(string question)
{
	cout << question << endl;
	cin >> charInput;
	return charInput;
}

void Player::updateScore()
{
	playerScore += runningScore;
	runningScore = 0;
}


void Player::displayInfo()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Player Name: " << playerName << endl;
	cout << "score: " << playerScore << endl;
	cout << "Running Score: " << runningScore << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Dices: \n";
	createDiceArt();
}

void Player::addDice()
{
	Die die1;
	Die die2;
	Die die3;
	Die die4;
	Die die5;
	Die die6;
	vDice.push_back(die1);
	vDice.push_back(die2);
	vDice.push_back(die3);
	vDice.push_back(die4);
	vDice.push_back(die5);
	vDice.push_back(die6);
	checkFarkle();
	reroll = false;
}

void Player::rerollDice()
{
	if (reroll==true)
	{
		vector<Die>::iterator iter;
		for (iter = vDice.begin(); iter != vDice.end(); iter++)
		{
			iter->rollDie();
		}
	}
	else if(reroll==false)
	{
		cout << "Store at least 1 die to reroll!";
	}
	reroll = false;
}

void Player::keepDie()
{
	int value, position;
	askForChar("Please enter the dice you want to keep (enter one at a time) press [d]one if you are finished.");
	while (charInput!='d')
	{
		position = (int)charInput - 49;
		if (position >= 0 && position < 6)
		{
			value = vDice[position].getDieValue();
			vDice[position].resetDie(); //for setting the die value to 0
			vKeptDice.push_back(value);
		}
		cin >> charInput;
	}
	checkMeld();
	reroll = true;
}

void Player::checkMeld()
{
	int diceList[6]{ 0,0,0,0,0,0 };
	int pair = 0;
	int triple = 0;
	int quad = 0;
	int value;
	for (int i = 0; i < vKeptDice.size(); i++)
	{
		value = vKeptDice[i];
		if (value == 1)
		{
			diceList[0]++;
			runningScore += 100;
		}
		else if (value == 2)
		{
			diceList[1]++;
		}
		else if (value == 3)
		{
			diceList[2]++;
		}
		else if (value == 4)
		{
			diceList[3]++;
		}
		else if (value == 5)
		{
			diceList[4]++;
			runningScore += 50;
		}
		else
		{
			diceList[5]++;
		}
		//checking for ones

		for (int a = 0; a < 6; a++)
		{
			if (diceList[a] == 2)
			{
				pair++;
			}
		}
		//checking for pairs

		if (diceList[0] == 3)
		{
			triple++;
			runningScore -= 300;
			runningScore += 300;
			pair--;
		}
		else if (diceList[1] == 3)
		{
			triple++;
			runningScore += 200;
			pair--;
		}
		else if (diceList[2] == 3)
		{
			triple++;
			runningScore += 300;
			pair--;
		}
		else if (diceList[3] == 3)
		{
			triple++;
			runningScore += 400;
			pair--;
		}
		else if (diceList[4] == 3)
		{
			triple++;
			runningScore -= 150;
			runningScore += 500;
			pair--;
		}
		else if (diceList[5] == 3)
		{
			triple++;
			runningScore += 600;
			pair--;
		}
		//checking for triples

		if (diceList[0] == 4)
		{
			quad++;
			runningScore -= 300;
			runningScore += 1000;
			triple--;
		}
		else if (diceList[1] == 4)
		{
			quad++;
			runningScore -= 200;
			runningScore += 1000;
			triple--;
		}
		else if (diceList[2] == 4)
		{
			quad++;
			runningScore -= 300;
			runningScore += 1000;
			triple--;
		}
		else if (diceList[3] == 4)
		{
			quad++;
			runningScore -= 400;
			runningScore += 1000;
			triple--;
		}
		else if (diceList[4] == 4)
		{
			quad++;
			runningScore -= 500;
			runningScore += 1000;
			triple--;
		}
		else if (diceList[5] == 4)
		{
			quad++;
			runningScore -= 600;
			runningScore += 1000;
			triple--;
		}
		//checking for four of a kind

		for (int b = 0; b < 6; b++)
		{
			if (diceList[b] == 5)
			{
				runningScore = 0;
				runningScore += 2000;
			}
		}
		//checking for five of a kind

		for (int c = 0; c < 6; c++)
		{
			if (diceList[c] == 6)
			{
				runningScore = 0;
				runningScore += 3000;
			}
		}
		//checking for six of a kind

		if (diceList[0] == 1 && diceList[1] == 1 && diceList[2] == 1 && diceList[3] == 1 && diceList[4] == 1 && diceList[5] == 1)
		{
			runningScore = 0;
			runningScore += 2500;
		}
		//checking for a run/straight(1-6)

		if (pair == 3)
		{
			runningScore = 0;
			runningScore += 1500;
		}
		//checking for triple pair

		if (quad == 1 && pair == 1)
		{
			runningScore = 0;
			runningScore += 1500;
		}
		//checking for a four of a kind + a pair

		if (triple == 2)
		{
			runningScore = 0;
			runningScore += 2500;
		}
		//checking for a double three of a kind
	}
	vKeptDice.clear();
}

void Player::checkFarkle()//still need to fix this
{
	int diceList[6]{ 0,0,0,0,0,0 };
	int pair = 0;
	int triple = 0;
	int run = 0;
	for (int i = 0; i < vDice.size(); i++)
	{
		int value = vDice[i].getDieValue();
		if (value == 1)
		{
			diceList[0]++;
		}
		else if (value == 2)
		{
			diceList[1]++;
		}
		else if (value == 3)
		{
			diceList[2]++;
		}
		else if (value == 4)
		{
			diceList[3]++;
		}
		else if (value == 5)
		{
			diceList[4]++;
		}
		else
		{
			diceList[5]++;
		}
		//checking for ones

		for (int a = 0; a < 6; a++)
		{
			if (diceList[a] == 2)
			{
				pair++;
			}
		}
		//checking for pairs

		if (diceList[0] == 3)
		{
			triple++;
			pair--;
		}
		else if (diceList[1] == 3)
		{
			triple++;
			pair--;
		}
		else if (diceList[2] == 3)
		{
			triple++;
			pair--;
		}
		else if (diceList[3] == 3)
		{
			triple++;
			pair--;
		}
		else if (diceList[4] == 3)
		{
			triple++;
			pair--;
		}
		else if (diceList[5] == 3)
		{
			triple++;
			pair--;
		}
		//checking for triples

		if (diceList[0] == 1 && diceList[1] == 1 && diceList[2] == 1 && diceList[3] == 1 && diceList[4] == 1 && diceList[5] == 1)
		{
			run++;
		}
		//checking for a run/straight(1-6)
	}

	if (pair < 3 && triple < 1 && run < 1 && diceList[0] < 1 && diceList[4] < 1)
	{
		farkle = true;
		farkleDisplay();
	}

	if (farkle==true)
	{
		cout << getPlayerName() << " just farkled!";
	}
}
	
void Player::createDiceArt()
{
	stringstream diceArt;
	stringstream dieLayer[5];
	if (vDice.size() == 0)
	{
		cout << "Not holing any die\n";
	}
	else
	{
		vector<Die>::iterator iter;
		for (iter = vDice.begin(); iter != vDice.end(); iter++)
		{
			int value = iter->getDieValue();
			if (value == 1)
			{
				dieLayer[0] << "*-------* ";
				dieLayer[1] << "|       | ";
				dieLayer[2] << "|   O   | ";
				dieLayer[3] << "|       | ";
				dieLayer[4] << "*-------* ";
			}
			else if (value == 2)
			{
				dieLayer[0] << "*-------* ";
				dieLayer[1] << "| O     | ";
				dieLayer[2] << "|       | ";
				dieLayer[3] << "|     O | ";
				dieLayer[4] << "*-------* ";
			}
			else if (value == 3)
			{
				dieLayer[0] << "*-------* ";
				dieLayer[1] << "|O      | ";
				dieLayer[2] << "|   O   | ";
				dieLayer[3] << "|      O| ";
				dieLayer[4] << "*-------* ";
			}
			else if (value == 4)
			{
				dieLayer[0] << "*-------* ";
				dieLayer[1] << "| O   O | ";
				dieLayer[2] << "|       | ";
				dieLayer[3] << "| O   O | ";
				dieLayer[4] << "*-------* ";
			}
			else if (value == 5)
			{
				dieLayer[0] << "*-------* ";
				dieLayer[1] << "| O   O | ";
				dieLayer[2] << "|   O   | ";
				dieLayer[3] << "| O   O | ";
				dieLayer[4] << "*-------* ";
			}
			else if (value == 6)
			{
				dieLayer[0] << "*-------* ";
				dieLayer[1] << "| O   O | ";
				dieLayer[2] << "| O   O | ";
				dieLayer[3] << "| O   O | ";
				dieLayer[4] << "*-------* ";
			}
			else
			{
				dieLayer[0] << "*-------* ";
				dieLayer[1] << "|       | ";
				dieLayer[2] << "|   X   | ";
				dieLayer[3] << "|       | ";
				dieLayer[4] << "*-------* ";
			}
		}
		for (int i = 0; i < 5; i++)
		{
			dieLayer[i] << endl;
			diceArt << dieLayer[i].str();
		}
		cout << diceArt.str();
	}
}

void Player::bank()
{
	if (runningScore > minimumBank)
	{
	playerScore += runningScore;
	runningScore = 0;
	cout << playerName << " just banked!\n";
	vDice.clear();
	}
	else
	{
		cout << "You haven't reached the minimum amount to bank!\n";
		vDice.clear();
	}
}

void Player::playerTurn()
{
	charInput = 'a';
	addDice();
	while (charInput != 'b' && charInput != 'q' && farkle != true)
	{
	displayInfo();
	cout << "Its your turn " << getPlayerName() << " do you want to [r]oll, [b]ank, [k]eep, [h]elp or [q]uit?";
	cin >> charInput;
		switch (charInput)
		{
		case 'r':
			rerollDice();
			displayInfo();
			checkFarkle();
			waitForPlayer();
			break;
		case'b':
			bank();
			displayInfo();
			waitForPlayer();
			break;
		case'k':
			keepDie();
			displayInfo();
			waitForPlayer();
			break;
		case 'h':
			displayRule("FarkleAbout.txt");
			waitForPlayer();
			break;
		case'q':
			cout << "Thanks For Playing!\n";
			exit(0);
			break;
		default:
			cout << "Error!\n";
			cout << "Its your turn " << getPlayerName() << " do you want to [r]oll, [b]ank, [k]eep, [h]elp or [q]uit?";
			cin >> charInput;
			break;
		}
	}
}

void Player::displayRule(string ruleFile)
{
	string line;
	fstream fileToRead;
	ruleFile = "FarkleAbout.txt";
	fileToRead.open(ruleFile);
	if (fileToRead.is_open())
	{
		while (!fileToRead.eof())
		{
			getline(fileToRead, line);
			cout << line << endl;
		}
	}
	else
	{
		cout << "Error! File is not found!\n";
	}
	fileToRead.close();
}

void Player::waitForPlayer()
{
	system("pause");
	system("CLS");
}

void Player::checkDieCount()
{
	int valueList[6]{ 0,0,0,0,0,0 };
	for (int i = 0; i < 6; i++)
	{
		valueList[i] = vDice[i].getDieValue();
	}
	if (valueList[0] == 0 && valueList[1] == 0 && valueList[2] == 0 && valueList[3] == 0 && valueList[4] == 0 && valueList[5] == 0)
	{
		for (int a = 0; a < 6; a++)
		{
			vDice[a].rollDie();
		}
	}
}

void Player::farkleDisplay()
{
	if (farkle==true)
	{
		cout << playerName << " just farkled!";
	}
}

void Player::winGameDisplay()
{
	cout << playerName << " just won the game with the score of : " << playerScore;
	cout << "***********************************************************************************************************************\n";
	cout << "\t\t\t\t\tCongratulations! " << playerName;
	cout << "***********************************************************************************************************************\n";
}