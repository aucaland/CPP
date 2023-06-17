//
// Created by aucaland on 5/9/23.
//

#pragma once

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <cstdlib>
#include <exception>
#include <sstream>
#include <time.h>


using std::string;
using std::vector;

# define INSERTION_LIMIT	64

class PmergeMe
{
private:
	char**				_unsortedElems;
	int 				_sequenceSize;
	std::deque<int>		_dequeElems;
	std::vector<int>	_vectorElem;

	PmergeMe();
	void	printVector();
	void	printDeque();
	void	printUnsortedElems();

	void	parsing();

	void	sortVector(int begin, int end);
	void	insertionSortVector(int end);
	void	mergeVector(int begin, int middle, int end);

	void	sortDq(int begin, int end);
	void	insertionDq(int begin, int end);
	void	mergeDq(int begin, int middle, int end);


public:

	char**	getUnsortedElems(void) const;

	PmergeMe( char** unsortedElems );
	PmergeMe(PmergeMe const &src);
	PmergeMe&	operator=(PmergeMe const &assign);
	~PmergeMe();


};
