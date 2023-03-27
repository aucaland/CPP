//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
#include "AMateria.h"
using std::string;


class ICharacter
{
public:
	ICharacter();

	virtual ~ICharacter();

	ICharacter &operator=(const ICharacter &);
	ICharacter(const ICharacter &);

	virtual string const &getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;

};


#endif //CPP_ICHARACTER_H
