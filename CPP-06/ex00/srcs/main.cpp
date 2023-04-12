//
// Created by aurel on 4/12/23.
//
#include "../incs/ScalarConversion.h"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << "Only one argument is allowed" << endl;
		return 0;
	}
	ScalarConversion::convert( av[1] );
}