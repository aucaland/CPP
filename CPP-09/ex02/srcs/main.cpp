//
// Created by aucaland on 5/9/23.
//
#include "../incs/PmergeMe.h"

int main(int argc, char **argv)
{
	try
	{
		PmergeMe Pmerge( argv, argc);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}