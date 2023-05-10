//
// Created by aucaland on 5/9/23.
//

#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <cstdlib>
#include <exception>
#include "errors.h"
#include <sstream>


using std::string;
using std::list;
using std::vector;


class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe( char ** sequence, int argc );
	PmergeMe &operator=(const PmergeMe &);
	PmergeMe(const PmergeMe &);

	void checkError( string elem, int argc );
	void fillPairedLists( string elem );
	void insertVector( string elem );

	bool isNumber( string elem );

private:
	list<int>	sortedList;
	list<int>	*pairedLists;
	vector<int>	sortedVector;
	int 		sequenceSize;

class parsingException : public std::exception
{
public:
	parsingException( const char* messageError ) {};
	virtual const char* what() const throw();
};

};

