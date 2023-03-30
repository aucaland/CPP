//
// Created by aucaland on 3/27/23.
//

#include "../incs/Cure.h"
#include "../incs/AMateria.h"
using std::cout;
using std::endl;

Cure::Cure() : AMateria(){
	cout << "Constructor Cure called" << endl;
}

Cure::~Cure() {
	cout << "Destructor Cure called" << endl;
}

void Cure::use( ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure();
}

