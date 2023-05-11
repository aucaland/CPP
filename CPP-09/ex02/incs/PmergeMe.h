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

	~PmergeMe();
	PmergeMe( char ** sequence, int argc );
//	PmergeMe &operator=(const PmergeMe &);
//	PmergeMe(const PmergeMe &);

	void listWay();
//	void vectorWay();
	void checkError( string elem, int argc , int i);
	void fillPairedLists();
//	void insertVector( string elem );
	int setPairedListQuantity() const;
	list<int>::iterator getSortedListIt();
	list<int>::iterator getEndSortedListIt();

	bool isNumber( string elem );

private:
	PmergeMe();
	int 		sequenceSize;
	list<int>	*pairedLists;
	int 		pairedListQuantity;
	list<int>	fullList;
	vector<int>	sortedVector;

class parsingException : public std::exception
	{
	public:
		explicit parsingException( const char* messageError );
		virtual const char* what() const throw();
	private:
		const char* msg;
	};

};

