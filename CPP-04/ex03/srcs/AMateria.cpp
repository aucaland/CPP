//
// Created by aucaland on 3/27/23.
//

#include "../incs/AMateria.h"

using std::cout;
using std::endl;

AMateria::AMateria() {
	cout << "Constructor AMateria called" << endl;
}

AMateria::~AMateria() {
	cout << "Destructor AMateria called" << endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type) {
	cout << "Copy constructor AMateria called" << endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other)
		this->_type = other._type;
	cout << "Constructor assignement AMateria called" << endl;
	return *this;
}

AMateria::AMateria( const string &type ) : _type(type)
{

}

string const &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use( ICharacter &target )
{
	cout << "AMateria " << this->_type << " used on " << target.getName() << endl;
}
