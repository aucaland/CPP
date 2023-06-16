//
// Created by aurel on 6/16/23.
//

#include "../incs/PmergeMe.h"

using std::cout;
using std::endl;

PmergeMe::~PmergeMe() {
	cout << "Destructor PmergeMe called" << endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
	cout << "Copy constructor PmergeMe called" << endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other)
	{
		this->_unsortedElems = getUnsortedElems();
	}
	cout << "Copy assignement PmergeMe called" << endl;
	return *this;
}

void PmergeMe::printVector() {
	std::vector<int>::iterator it = this->_vectorElem.begin();
	std::cout << "After:";
	for (; it != this->_vectorElem.end() ; ++it) {
//		if ( *it == this->_vectorElem[6] )
//			break ;
		std::cout << " " << *it;
	}
	std::cout << "[...]" <<  endl;
}

void PmergeMe::parsing() {
	int i = 1;
	while ( this->_unsortedElems[i] )
	{
		int value;
		std::istringstream ss(this->_unsortedElems[i]);
		ss >> value;
		if ( ss.fail() || !ss.eof() )
			throw std::runtime_error("Error: Elements must be integer");
		this->_dequeElems.push_back(value);
		this->_vectorElem.push_back(value);
		i++;
	}
}

PmergeMe::PmergeMe(char **unsortedElems) : _unsortedElems(unsortedElems) {
	clock_t startClock, endClock;
	double timeV, timeD;

	(void) timeD;
	parsing();
	printUnsortedElems();
	startClock = clock();
	sortVector(0, this->_vectorElem.size() - 1);
	endClock = clock();
	timeV = static_cast<double>(endClock - startClock) / CLOCKS_PER_SEC * 1000000;
	printVector();
	std::cout << "TIMEV: " << timeV << " µs." << std::endl;
}

char **PmergeMe::getUnsortedElems(void) const {
	return this->_unsortedElems;
}

void PmergeMe::printUnsortedElems() {
	std::vector<int>::iterator it = this->_vectorElem.begin();
	std::cout << "Before:";
	for (; it != this->_vectorElem.end() ; ++it) {
//		if ( *it == this->_vectorElem[6] )
//			break ;
		std::cout << " " << *it;
	}
	std::cout << "[...]" << endl;
}

void PmergeMe::sortVector(int begin, int end) {
	if ( end - begin > INSERTION_LIMIT )
	{
		int middle = ( begin + end ) / 2;
		sortVector( begin, middle );
		sortVector( middle + 1, end );
		mergeVector( begin, middle, end );
	}
	else
		insertionSortVector( end );
}

void PmergeMe::insertionSortVector(int end) {
	int key, j;
	for (int i = 1;  i < end + 1; ++i) {
		key = this->_vectorElem[i];
		j = i - 1;
		while ( j >= 0 && this->_vectorElem[j] > key ) {
			this->_vectorElem[j + 1] = this->_vectorElem[j];
			j = j - 1;
		}
		this->_vectorElem[j + 1] = key;
	}
}

void PmergeMe::mergeVector(int begin, int middle, int end) {
	std::vector<int> leftVec(this->_vectorElem.begin() + begin, this->_vectorElem.begin() + middle + 1);
	std::vector<int> rightVec(this->_vectorElem.begin() + middle + 1, this->_vectorElem.begin() + end + 1);
	int i = begin, right = 0, left = 0, first = middle - begin + 1, second = end - middle;
	for (; i <= end; ++i) {
		if (right == second)
		{
			this->_vectorElem[i] = leftVec[left];
			left++;
		}
		else if (left == first)
		{
			this->_vectorElem[i] = rightVec[right];
			right++;
		}
		else if (rightVec[right] > leftVec[left])
		{
			this->_vectorElem[i] = leftVec[left];
			left++;
		}
		else
		{
			this->_vectorElem[i] = rightVec[right];
			right++;
		}

	}
//	std::vector<int>::iterator it = this->_vectorElem.begin();
//	std::cout << "TEST:";
//	for (; it != this->_vectorElem.end() ; ++it) {
////		if ( *it == this->_vectorElem[6] )
////			break ;
//		std::cout << " " << *it;
//	}
//	std::cout << "[...]" <<  endl;
}
