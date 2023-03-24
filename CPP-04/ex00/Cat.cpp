//
// Created by aucaland on 3/24/23.
//

#include "Cat.h"

using std::cout;
using std::endl;

Cat::Cat() {
	cout << "Constructor Cat called" << endl;
}

Cat::~Cat() {
	cout << "Destructor Cat called" << endl;
}

Cat::Cat(const Cat &other) {
	cout << "Copy constructor Cat called" << endl;
}

Cat &Cat::operator=(const Cat &other) {
	cout << "Constructor assignement Cat called" << endl;
	return *this;
}
