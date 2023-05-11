//
// Created by aucaland on 5/9/23.
//
#include "../incs/PmergeMe.h"

int main(int argc, char **argv)
{
//	(void )argv;
//	(void)argc;
//	int t1[] = { 1, 5, 3, 10};
//	int t2[] = { 3, 0, 6, 2};
//	list<int> test(t1, t1+3);
//	list<int> test2(t2, t2+3);
//	test.sort();
//	test2.sort();
//	test.merge(test2);
//	list<int>::iterator it1 = test.begin();
//	for (; it1 != test.end() ; ++it1) {
//		std::cout << *it1 << std::endl;
//	}
	try
	{
		PmergeMe Pmerge( argv, argc);
		list<int>::iterator it = Pmerge.getSortedListIt();

		for (; it != Pmerge.getEndSortedListIt() ; it++ ) {
			std::cout << *it << " " << std::flush;
		}
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}