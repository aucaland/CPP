//
// Created by aucaland on 3/27/23.
//

#include "../incs/Character.h"

using std::cout;
using std::endl;

Character::Character() {
	cout << "Constructor Character called" << endl;
}

Character::~Character() {
	cout << "Destructor Character called" << endl;
}

Character::Character(const Character &other) {
	cout << "Copy constructor Character called" << endl;
}

Character &Character::operator=(const Character &other) {
	if (this == &other)
		return *this;
	
	cout << "Constructor assignement Character called" << endl;
	return *this;
}
