//
// Created by aucaland on 3/27/23.
//

#include "Cure.h"

using std::cout;
using std::endl;

Cure::Cure() {
	cout << "Constructor Cure called" << endl;
}

Cure::~Cure() {
	cout << "Destructor Cure called" << endl;
}

Cure::Cure(const Cure &other) {
	cout << "Copy constructor Cure called" << endl;
}

Cure &Cure::operator=(const Cure &other) {
	cout << "Constructor assignement Cure called" << endl;
	return *this;
}
