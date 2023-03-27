//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
#include "AMateria.h"

using std::string;


class IMateriaSource
{
public:
	IMateriaSource();

	virtual ~IMateriaSource();

	IMateriaSource &operator=(const IMateriaSource &);

	IMateriaSource(const IMateriaSource &);

	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif //CPP_IMATERIASOURCE_H
