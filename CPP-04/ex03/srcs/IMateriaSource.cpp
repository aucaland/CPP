//
// Created by aucaland on 3/27/23.
//

#include "../incs/IMateriaSource.h"

using std::cout;
using std::endl;

IMateriaSource::IMateriaSource() {
	cout << "Constructor IMateriaSource called" << endl;
}

IMateriaSource::~IMateriaSource() {
	cout << "Destructor IMateriaSource called" << endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &other) {
	cout << "Copy constructor IMateriaSource called" << endl;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &other) {
	cout << "Constructor assignement IMateriaSource called" << endl;
	return *this;
}
