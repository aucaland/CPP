//
// Created by aucaland on 3/27/23.
//

#include "../incs/MateriaSource.h"

using std::cout;
using std::endl;

MateriaSource::MateriaSource() {
	cout << "Constructor MateriaSource called" << endl;
}

MateriaSource::~MateriaSource() {
	cout << "Destructor MateriaSource called" << endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	cout << "Copy constructor MateriaSource called" << endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	cout << "Constructor assignement MateriaSource called" << endl;
	return *this;
}
