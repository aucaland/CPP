//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
#include "AMateria.h"
#include "ICharacter.h"
using std::string;


class Cure : public AMateria
{
public:
	Cure();
	AMateria* clone() const;
	void 	use(ICharacter& target);
};

