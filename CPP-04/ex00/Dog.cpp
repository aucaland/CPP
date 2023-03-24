//
// Created by aucaland on 3/24/23.
//

#include "Dog.h"

using std::cout;
using std::endl;

Dog::Dog() {
	cout << "Constructor Dog called" << endl;
}

Dog::~Dog() {
	cout << "Destructor Dog called" << endl;
}

Dog::Dog(const Dog &other) {
	cout << "Copy constructor Dog called" << endl;
}

Dog &Dog::operator=(const Dog &other) {
	cout << "Constructor assignement Dog called" << endl;
	return *this;
}
