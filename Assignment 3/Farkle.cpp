#include "Farkle.h"


Farkle::Farkle()
{
	resetGame();
	displayTitle();
	displayRule("FarkleAbout.txt");
	waitForPlayer();
	Player player1;
	Player player2;
	vPlayer.push_back(player1);
	vPlayer.push_back(player2);
}

Farkle::~Farkle()
{
}

void Farkle::displayTitle()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "***********************************************************************************************************************\n";
	cout << "\t\t\t\t\t\tWelcome to FARKLE\n";
	cout << "***********************************************************************************************************************\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void Farkle::waitForPlayer()
{
	system("pause");
	system("CLS");
}

void Farkle::playFarkle()
{
	while (targetScore > playerScore)
	{
		for (int i = 0;  i < vPlayer.size();  i++)
		{
		vPlayer[i].playerTurn();
		checkGameOver();
		}
	}
}

void Farkle::gameOver()
{
	
	string question = "Do you want to play again? (y/n)\n";
	while (charInput!='y'&&charInput!='n')
	{
	askForLetter(question);
		if (charInput == 'y')
		{
			playFarkle();
		}
		else if (charInput == 'n')
		{
			cout << "Thanks For Playing!" << endl;
			exit(0);
		}
		else
		{
			cout << "Error! please enter (y/n).\n";
		}
	}
}

char Farkle::askForLetter(string question)
{
	cout << question;
	cin >> charInput;
	return charInput;
}

int Farkle::askForInt(string question)
{
	cout << question;
	cin >> intInput;
	return intInput;
}

bool Farkle::checkGameOver()
{
	if (playerScore>targetScore)
	{
		return true;
		winGameDisplay();
		gameOver();
	}
	else
	{
		return false;
	}
}

void Farkle::quitGame()
{
	cout << "Thanks For Playing!\n";
	exit(0);
}


void Farkle::setTargetScore()
{
	intInput = 0;
	cout << "Set difficulty level: \t[1]Rookie\t[2]Roller\t[3]High Roller\n";
	while (intInput != 1 && intInput != 2 && intInput !=3)
	{
		askForInt("Target Score\t: \t5000\t\t10.000\t\t20.000\n");
		switch (intInput)
		{
		case 1:
			targetScore = 5000;
			minimumBank = 250;
			cout << "You Have Picked the [R]ookie Table!\n";
			break;
		case 2:
			targetScore = 10000;
			minimumBank = 500;
			cout << "You Have Picked the [R]oller Table!\n";
			break;
		case 3:
			targetScore = 20000;
			minimumBank = 750;
			cout << "You Have Picked the [H]igh Roller Table!\n";
			break;
		default:
			cout << "Invalid difficulty! please enter (1-3)\n";
			break;
		}
	}
}

void Farkle::mainMenu()
{
	displayTitle();
	cout << "***********************************************************************************************************************\n";
	cout << "\t\t\t\t\t\tMAIN MENU\n";
	cout << "***********************************************************************************************************************\n";
	cout << "[1]Play Game\n";
	cout << "[2]How To Play\n";
	cout << "[3]Options\n";
	cout << "[4]Change Name\n";
	cout << "[5] Quit\n";
	askForInt("Select A Menu: (1-5)\n");
	switch (intInput)
	{
	case 1:
		playFarkle();
		waitForPlayer();
		mainMenu();
		break;
	case 2:
		displayRule("FarkleAbout.txt");
		waitForPlayer();
		mainMenu();
		break;
	case 3:
		setTargetScore();
		waitForPlayer();
		mainMenu();
		break;
	case 4:
		for (int  i = 0; i < vPlayer.size(); i++)
		{
			vPlayer[i].setPlayer();
		}
		waitForPlayer();
		mainMenu();
		break;
	case 5:
		quitGame();
		break;
	default:
		cout << "Error! Plese enter number 1-5\n";
		break;
	}
}

void Farkle::resetGame()
{
	targetScore = 5000;
	minimumBank = 250;
	playerScore = 0;
}