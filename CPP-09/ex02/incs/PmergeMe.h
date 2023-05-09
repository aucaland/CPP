//
// Created by aucaland on 5/9/23.
//

#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <cstdlib>


using std::string;
using std::list;
using std::vector;


class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe( char ** elemToMerge );
	PmergeMe &operator=(const PmergeMe &);
	PmergeMe(const PmergeMe &);

	void checkError( char *sequence );
	void fillPairedLists( char *sequence );
	
	void insertVector( char *sequence );

private:
	list<int> sortedList;
	list<int> *pairedList;
	vector<int> sortedVector;
};

