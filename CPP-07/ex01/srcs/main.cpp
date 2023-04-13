//
// Created by aurel on 4/13/23.
//
#include "../incs/iter.h"

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string arrC[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};

	int length = 5;
	unsigned int lengthU= 5;

	iter(arrC, length, printElem<std::string>);
	iter(arr, length, printElem<unsigned int>);

	iter(arrC, lengthU, printElem<std::string>);
	iter(arr, lengthU, printElem<unsigned int >);
}