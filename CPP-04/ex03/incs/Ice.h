//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
#include "ICharacter.h"
using std::string;


class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	AMateria* clone() const;
	void 	use(ICharacter& target);
};


#endif //CPP_ICE_H
