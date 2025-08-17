#include "Die.h"

Die::Die()
{
	dieValue = rand() % 6 + 1;
}

Die::~Die()
{
}

void Die::rollDie()
{
	if (dieValue!=0)
	{
	dieValue = rand() % 6 + 1;
	}
}

int Die::getDieValue()
{
	return dieValue;
}

void Die::resetDie()
{
	dieValue = 0;
}