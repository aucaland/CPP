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
		}
		i++;
	}
	listWay();
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

	if (elem[i] == '-' || elem[i] == '+')
		i++;
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

list<int>::iterator PmergeMe::getSortedListIt() {
	return this->fullList.begin();
}

list<int>::iterator PmergeMe::getEndSortedListIt() {
	return this->fullList.end();
}

int PmergeMe::setPairedListQuantity() const{
	if (this->sequenceSize <= CHUNCK_SIZE)
		return 1;
	else if (this->sequenceSize % CHUNCK_SIZE != 0)
		return this->sequenceSize / CHUNCK_SIZE + 1;
	else
		return this->sequenceSize / 32;
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

}

PmergeMe::parsingException::parsingException(const char *messageError) {
	this->msg = messageError;
}

const char *PmergeMe::parsingException::what() const throw() {
	return this->msg;
}