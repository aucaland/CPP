//
// Created by aucaland on 3/27/23.
//

#include "ICharacter.h"

using std::cout;
using std::endl;

ICharacter::ICharacter() {
	cout << "Constructor ICharacter called" << endl;
}

ICharacter::~ICharacter() {
	cout << "Destructor ICharacter called" << endl;
}

ICharacter::ICharacter(const ICharacter &other) {
	cout << "Copy constructor ICharacter called" << endl;
}

ICharacter &ICharacter::operator=(const ICharacter &other) {
	cout << "Constructor assignement ICharacter called" << endl;
	return *this;
}
