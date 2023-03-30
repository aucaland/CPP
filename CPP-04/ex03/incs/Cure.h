//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
#include "ICharacter.h"
using std::string;


class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	AMateria* clone() const;
	void 	use(ICharacter& target);
};


#endif //CPP_CURE_H
