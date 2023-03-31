//
// Created by aucaland on 3/27/23.
//

#include "../incs/MateriaSource.h"

using std::cout;
using std::endl;

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	cout << "Constructor MateriaSource called" << endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	cout << "Destructor MateriaSource called" << endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	*this = other;
	cout << "Copy constructor MateriaSource called" << endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
		if (other._materias[i] != NULL)
			this->_materias[i] = other._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
	cout << "Constructor assignement MateriaSource called" << endl;
	return *this;
}

AMateria *MateriaSource::createMateria( const string &type )
{
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type) {
			return this->_materias[i];
		}
	}
	return NULL;
}

AMateria *MateriaSource::getMateria( const string &type )
{
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone();
		}
	}
	return NULL;
}

void MateriaSource::learnMateria( AMateria *m )
{
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] == NULL) {
			this->_materias[i] = m;
			return ;
		}
	}
	std::cout << "Can't learn any more materia" << std::endl;
}
