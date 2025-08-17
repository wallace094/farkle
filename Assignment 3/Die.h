#ifndef DIE_H
#define DIE_H
#include <ctime>
#include <iostream>
class Die
{
private:
	int dieValue;
public:
	Die();
	~Die();
	void rollDie();
	int getDieValue();
	void resetDie();
};
#endif


