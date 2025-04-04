//
// Created by aucaland on 3/27/23.
//

#include "../incs/Ice.h"

using std::cout;
using std::endl;

Ice::Ice() : AMateria() {
	this->_type = "ice";
	cout << "Constructor Ice called" << endl;
}

void Ice::use( ICharacter & target )
{
	std::cout << "* shoot an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice();
}

