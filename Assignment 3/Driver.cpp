#include "Farkle.h"

int main()
{
	srand(unsigned(time(NULL)));
	Farkle* pGame=new Farkle;
	pGame->mainMenu();
	delete pGame;
	return 0;
}