//
// Created by aucaland on 5/9/23.
//
#include "../incs/PmergeMe.h"

int main(int argc, char **argv)
{
	if ( argc < 3 )
	{
		std::cout << "Error: invalid arguments, 2 args min." << std::endl;
		exit(0);
	}
	try
	{
		PmergeMe Pmerge( argv );
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}