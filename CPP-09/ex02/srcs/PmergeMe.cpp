//
// Created by aucaland on 5/9/23.
//

#include "../incs/PmergeMe.h"

using std::cout;
using std::endl;

PmergeMe::PmergeMe() {
	cout << "Constructor PmergeMe called" << endl;
}

PmergeMe::~PmergeMe() {
	cout << "Destructor PmergeMe called" << endl;
}

//PmergeMe::PmergeMe(const PmergeMe &other) {
//	cout << "Copy constructor PmergeMe called" << endl;
//}
//
//PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
//	cout << "Constructor assignement PmergeMe called" << endl;
//	return *this;
//}

PmergeMe::PmergeMe(char **sequence, int argc) : sequenceSize(argc - 1), pairedLists(NULL), pairedListQuantity(setPairedListQuantity()) {
	string	str;
	int i = 0;

	checkError( str, argc , i);
    clock_t startListTime;
	clock_t endListTime;
//    clock_t startVectTime = clock();
	while ( i < argc )
	{
		int toInt;

		if (i > 0)
		{
			str = string( sequence[i] );
			checkError( str, argc , i);
			std::stringstream ss( str );
			ss >> toInt;
			this->fullList.push_back( toInt );
			this->fullListWithLib.push_back( toInt );
			this->originalListCopy.push_back( toInt );
		}
		i++;
	}
	startListTime = clock();
	listWay();
	endListTime = clock();
	this->listTime = static_cast<double>(endListTime - startListTime) / CLOCKS_PER_SEC * 1000000;
	startListTime = clock();
	listWayWithLib();
	endListTime = clock();
	this->listTimeWithLib = static_cast<double>(endListTime - startListTime) / CLOCKS_PER_SEC * 1000000;
	printContainers();
	printTime();
}

void PmergeMe::checkError( string elem, int argc , int i) {
	int toInt;
	std::stringstream ss( elem );
	if ( argc <= 2 )
		throw parsingException( ERROR_NOT_ENOUGH_ARG );
	else if ( elem.empty() && i != 0) {
		throw parsingException( ERROR_EMPTY_STRING );
	}
	else if ( !isNumber( elem ) && i != 0) {
		throw parsingException( ERROR_INV_ARGUMENT );
	}
	ss >> toInt;
	if ( ss.fail() && i != 0)
		throw parsingException( ERROR_OUT_OF_INT_RANGE );

}

//void PmergeMe::insertVector( string elem ) {
//	return ;
//}

void PmergeMe::fillPairedLists() {
	int j = 0;

	this->pairedLists = new list<int>[this->pairedListQuantity];
	std::list<int>::iterator it = this->fullList.begin();
	for (; it != this->fullList.end(); it++)
	{
		int i = 0;
		this->pairedLists[j] = list<int>();
		while ( it != this->fullList.end() && i++ < CHUNCK_SIZE )
		{
			this->pairedLists[j].push_back( *it );
			it++;
		}
		it--;
		j++;
	}
}

bool PmergeMe::isNumber( string elem )
{
	size_t i = 0;

	if (elem[i] == '+')
		i++;
	else if (elem[i] == '-')
		return false;
	for (; i < elem.length(); ++i )
	{
		if (!isdigit(elem[i]))
			return false;
	}
	return true;
}

void PmergeMe::listWay()
{
	fillPairedLists();
	this->fullList.clear();
	listInsertionSort();
	if (this->pairedListQuantity == 1)
		this->fullList.insert(this->fullList.end(), this->pairedLists[0].begin(), this->pairedLists[0].end());
	else
		listMerge();
	delete[] this->pairedLists;
}

//void PmergeMe::vectorWay()
//{
//	return ;
//}

int PmergeMe::setPairedListQuantity() const{
	if (this->sequenceSize <= CHUNCK_SIZE)
		return 1;
	else if (this->sequenceSize % CHUNCK_SIZE != 0)
		return this->sequenceSize / CHUNCK_SIZE + 1;
	else
		return this->sequenceSize / CHUNCK_SIZE;
}

void PmergeMe::listInsertionSort()
{
	for ( int i = 0; i < this->pairedListQuantity; i++ )
	{
		std::list<int>::iterator it = this->pairedLists[i].begin()++;
		for ( ; it != this->pairedLists[i].end() ; it++ )
		{
			list<int>::iterator jt = it;
			while ( jt != this->pairedLists[i].begin() && *jt < *(--jt) )
			{
				jt++;
				std::list<int>::iterator swapt = --jt;
				++jt;
				std::iter_swap( jt, swapt);
				jt--;
			}
		}
	}
}

void PmergeMe::listMerge()
{
	int i = 1;
	for (; i <= this->pairedListQuantity; i++)
	{
		if (this->pairedLists[0].size() == (size_t)this->sequenceSize)
			break;
		std::list<int>::iterator it2 = this->pairedLists[i].begin();
		for (; it2 != this->pairedLists[i].end(); ++it2) {
			std::list<int>::iterator it = this->pairedLists[0].begin();
			while ( it != this->pairedLists[0].end() && *it < *it2 )
				it++;
			this->pairedLists[0].insert(it, 1, *it2);
		}
	}
	this->fullList.insert(this->fullList.end(), this->pairedLists[0].begin(), this->pairedLists[0].end());

}

void PmergeMe::printTime() {
	std::cout << "Time to process a range of " << this->sequenceSize << " elements with Container List: " << this->listTime << " \u00B5s." << std::endl;
	std::cout << "Time to process a range of " << this->sequenceSize << " elements with Container List and Lib sort/merge: " << this->listTimeWithLib << " \u00B5s." << std::endl;
}

void PmergeMe::listWayWithLib() {

	fillPairedListsWithLib();
	this->fullListWithLib.clear();
	for (int i = 0; i < this->pairedListQuantity; ++i) {
			this->pairedLists[i].sort();
	}
	for (int j = 0; j < this->pairedListQuantity; ++j) {
		this->fullListWithLib.merge(this->pairedLists[j]);
	}
	delete[] this->pairedLists;
}

void PmergeMe::fillPairedListsWithLib() {
	int j = 0;

	this->pairedLists = new list<int>[this->pairedListQuantity];
	std::list<int>::iterator it = this->fullListWithLib.begin();
	for (; it != this->fullListWithLib.end(); it++)
	{
		int i = 0;
		this->pairedLists[j] = list<int>();
		while ( it != this->fullListWithLib.end() && i++ < CHUNCK_SIZE )
		{
			this->pairedLists[j].push_back( *it );
			it++;
		}
		it--;
		j++;
	}
}

void PmergeMe::printContainers() {

	int counter = 0;
	int maxPrintable = 100;
	list<int>::iterator kt = this->originalListCopy.begin();
	std::cout << "Before: " << std::flush;
	for (; kt != (this->originalListCopy.end()) ; kt++) {
		std::cout << *kt << " " << std::flush;
		if (++counter == maxPrintable)
			break;
	}
	counter = 0;
	if (maxPrintable < this->sequenceSize)
		std::cout << "[...]" << std::flush;
	std::cout << std::endl;

	list<int>::iterator it = this->fullList.begin();

	std::cout << "After: " << std::flush;
	for (; it != this->fullList.end() ; it++ ) {
		std::cout << *it << " "<< std::flush;
		if (++counter == maxPrintable)
			break;
	}
	if (maxPrintable < this->sequenceSize)
		std::cout << "[...]" << std::flush;
	std::cout << std::endl;

//	list<int>::iterator jt = this->fullListWithLib.begin();
//
//	for (; jt != this->fullListWithLib.end() ; jt++ ) {
//		std::cout << *jt << " " << std::flush;
//	}
//	std::cout << std::endl;
}


PmergeMe::parsingException::parsingException(const char *messageError) {
	this->msg = messageError;
}

const char *PmergeMe::parsingException::what() const throw() {
	return this->msg;
}