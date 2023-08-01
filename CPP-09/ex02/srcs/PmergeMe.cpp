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
		this->_sequenceSize = other._sequenceSize;
		this->_dequeElems = other._dequeElems;
		this->_vectorElem = other._vectorElem;
	}
	cout << "Copy assignement PmergeMe called" << endl;
	return *this;
}

void PmergeMe::printVector() {
	std::vector<int>::iterator it = this->_vectorElem.begin();
	std::cout << "After:";
	for (; it != this->_vectorElem.end() ; ++it) {
		if ( *it == this->_vectorElem[10] )
			break ;
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
	this->_sequenceSize = i - 1;
}

PmergeMe::PmergeMe(char **unsortedElems) : _unsortedElems(unsortedElems) {
	clock_t startClock, endClock;
	double timeV, timeD;

	parsing();
	printUnsortedElems();
	startClock = clock();
	sortVector(0, this->_vectorElem.size() - 1);
	endClock = clock();
	timeV = static_cast<double>(endClock - startClock) / CLOCKS_PER_SEC * 1000000;

	startClock = clock();
	sortDeque( 0, this->_dequeElems.size() - 1 );
	endClock = clock();
	timeD = static_cast<double>(endClock - startClock) / CLOCKS_PER_SEC * 1000000;
	printVector();
//	printDeque();
	std::cout << "Time to process a range of " << this->_sequenceSize << " elements with Vector:     " << timeV << " \u00B5s." << std::endl;
	std::cout << "Time to process a range of " << this->_sequenceSize << " elements with Deque:     " << timeD << " \u00B5s." << std::endl;
}

char **PmergeMe::getUnsortedElems(void) const {
	return this->_unsortedElems;
}

void PmergeMe::printUnsortedElems() {
	std::vector<int>::iterator it = this->_vectorElem.begin();
	std::cout << "Before:";
	for (; it != this->_vectorElem.end() ; ++it) {
		if ( *it == this->_vectorElem[10] )
			break ;
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
	{
		insertionSortVector( end );
	}
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
//	std::cerr << "FIRST=" << first << endl;
//	std::cerr << "SECOND=" << second << endl;
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

void PmergeMe::sortDeque(int begin, int end) {
	if ( end - begin > INSERTION_LIMIT )
	{
		int middle = ( begin + end ) / 2;
		sortDeque( begin, middle );
		sortDeque( middle + 1, end );
		mergeDeque( begin, middle, end );
	}
	else
	{
		insertionSortDeque( end );
	}
}

void PmergeMe::insertionSortDeque(int end) {
	int key, j;
	for (int i = 1;  i < end + 1; ++i) {
		key = this->_dequeElems[i];
		j = i - 1;
		while ( j >= 0 && this->_dequeElems[j] > key ) {
			this->_dequeElems[j + 1] = this->_dequeElems[j];
			j = j - 1;
		}
		this->_dequeElems[j + 1] = key;
	}
}

void PmergeMe::mergeDeque(int begin, int middle, int end) {
	std::deque<int> leftDeque(this->_dequeElems.begin() + begin, this->_dequeElems.begin() + middle + 1);
	std::deque<int> rightDeque(this->_dequeElems.begin() + middle + 1, this->_dequeElems.begin() + end + 1);
	int i = begin, right = 0, left = 0, first = middle - begin + 1, second = end - middle;
//	std::cerr << "FIRST=" << first << endl;
//	std::cerr << "SECOND=" << second << endl;
	for (; i <= end; ++i) {
		if (right == second) {
			this->_dequeElems[i] = leftDeque[left];
			left++;
		} else if (left == first) {
			this->_dequeElems[i] = rightDeque[right];
			right++;
		} else if (rightDeque[right] > leftDeque[left]) {
			this->_dequeElems[i] = leftDeque[left];
			left++;
		} else {
			this->_dequeElems[i] = rightDeque[right];
			right++;
		}


	}
}

void PmergeMe::printDeque() {
	std::deque<int>::iterator it = this->_dequeElems.begin();
	std::cout << "After:";
	for (; it != this->_dequeElems.end() ; ++it) {
		if ( *it == this->_dequeElems[10] )
			break ;
		std::cout << " " << *it;
	}
	std::cout << "[...]" <<  endl;
}
