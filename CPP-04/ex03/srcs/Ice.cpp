//
// Created by aucaland on 3/27/23.
//

#include "Ice.h"

using std::cout;
using std::endl;

Ice::Ice() {
	cout << "Constructor Ice called" << endl;
}

Ice::~Ice() {
	cout << "Destructor Ice called" << endl;
}

Ice::Ice(const Ice &other) {
	cout << "Copy constructor Ice called" << endl;
}

Ice &Ice::operator=(const Ice &other) {
	cout << "Constructor assignement Ice called" << endl;
	return *this;
}
