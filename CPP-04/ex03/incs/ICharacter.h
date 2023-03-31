//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
#include "AMateria.h"
class AMateria;

using std::string;


class ICharacter
{
public:
	virtual ~ICharacter() {};
	virtual string const &getName() const = 0;
	virtual void equip(AMateria * m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;

};

