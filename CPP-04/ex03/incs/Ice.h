//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
#include "AMateria.h"
#include "ICharacter.h"
using std::string;


class Ice : public AMateria
{
public:
	Ice();
	AMateria* clone() const;
	void 	use(ICharacter& target);
};

