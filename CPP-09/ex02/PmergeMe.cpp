//
// Created by aucaland on 5/9/23.
//

#include "incs/PmergeMe.h"

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

PmergeMe::PmergeMe(char **elemToMerge) {
	do {
		checkError( *elemToMerge );
		fillPairedLists( *elemToMerge );
	} while ( ++elemToMerge );

}

void PmergeMe::checkError(char *sequence) {

}

void PmergeMe::insertVector(char *sequence) {

}

void PmergeMe::fillPairedLists(char *sequence) {

}
