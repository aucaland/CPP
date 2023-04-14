//
// Created by aurel on 4/13/23.
//
#include "../incs/Array.h"

#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}

//int main()
//{
//	/*		Test Int		*/
//
//	cout << RED << "INT:" << RESET << endl << endl;
//	Array<int> testInt(10);
//
//	for ( unsigned int i = 0; i < testInt.size(); i++ )
//	{
//		testInt[i] = (int)i;
//	}
//	cout << testInt << endl << RED << "STRING:" << RESET << endl << endl;
//
//	/*		Test string		*/
//
//	Array<std::string> testString( 10 );
//	try
//	{
//		testString[0] = "e";
//		testString[1] = "x";
//		testString[2] = "p";
//		testString[3] = "l";
//		testString[4] = "o";
//		testString[5] = "r";
//		testString[6] = "e";
//		testString[7] = "*";
//		testString[8] = "!";
//		testString[9] = "*";
//		testString[10] = "But out of range";
//	}
//	catch (std::exception & e)
//	{
//		cout << e.what() << endl;
//	}
//
//	cout << GRAY << "testString :" << RESET << endl << endl << testString << endl;
//	Array<std::string> copyTestString( testString );
//	for ( unsigned int i = 0; i < testString.size(); i++ )
//	{
//		copyTestString[i] = "None";
//	}
//	cout << GRAY << "CopyString :" << RESET << endl << endl << copyTestString << endl;
//
//}