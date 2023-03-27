//
// Created by aucaland on 3/27/23.
//

#include "AMateria.h"

using std::cout;
using std::endl;

AMateria::AMateria() {
	cout << "Constructor AMateria called" << endl;
}

AMateria::~AMateria() {
	cout << "Destructor AMateria called" << endl;
}

AMateria::AMateria(const AMateria &other) {
	cout << "Copy constructor AMateria called" << endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	cout << "Constructor assignement AMateria called" << endl;
	return *this;
}
