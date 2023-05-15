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
#include <time.h>


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

	void	listWay();
	void	listWayWithLib();
	void	listInsertionSort();
	void	listMerge();
//	void	vectorWay();
	void	checkError( string elem, int argc , int i);
	void	fillPairedLists();
	void	fillPairedListsWithLib();
//	void	insertVector( string elem );
	void	printTime();
	void 	printContainers();
	int		setPairedListQuantity() const;

	bool isNumber( string elem );

private:
	PmergeMe();
	int 		sequenceSize;
	list<int>	*pairedLists;
	int 		pairedListQuantity;
	list<int>	originalListCopy;
	list<int>	fullList;
	list<int>	fullListWithLib;
	vector<int>	fullVector;
	double		listTime;
	double		listTimeWithLib;
	double		vectTime;

class parsingException : public std::exception
	{
	public:
		explicit parsingException( const char* messageError );
		virtual const char* what() const throw();
	private:
		const char* msg;
	};

};

