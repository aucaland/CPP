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

PmergeMe::PmergeMe(const PmergeMe &other) {
	cout << "Copy constructor PmergeMe called" << endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	cout << "Constructor assignement PmergeMe called" << endl;
	return *this;
}

PmergeMe::PmergeMe(char **sequence, int argc) : sequenceSize(argc - 1), pairedLists(NULL) {
	string	str;
	int i = 1;

	while ( i < argc )
	{
		int toInt;

		str = string( sequence[i] );
		checkError( str, argc );
		std::stringstream ss( str );
		ss >> toInt;
		this->fullList.push_back( toInt );
		i++;
	}
}

void PmergeMe::checkError( string elem, int argc ) {
	if ( elem.empty() )
		throw parsingException( ERROR_EMPTY_STRING );
	else if ( !isNumber( elem ) )
		throw parsingException( ERROR_INV_ARGUMENT );
	else if ( argc == 2 )
		throw parsingException( ERROR_NOT_ENOUGH_ARG );
}

void PmergeMe::insertVector( string elem ) {

}

void PmergeMe::fillPairedLists( string elem ) {

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
	return true
}

void PmergeMe::listWay()
{
	int j = 0;

	this->pairedLists = new list<int>[this->sequenceSize / 2];
	std::list<int>::iterator it = this->fullList.begin();
	for (; it != this->fullList.end(); it++)
	{
		this->pairedLists[j] = list<int>();
		this->pairedLists[j++].push_back( *it );
		it++;
		if ( it != this->fullList.end() )
		{
			this->pairedLists[j++].push_back(*it);
			it++;
		}
	}
}

void PmergeMe::vectorWay()
{

}
