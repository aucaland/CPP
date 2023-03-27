//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
#include "../incs/IMateriaSource.h"
using std::string;


class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();

	~MateriaSource();

	MateriaSource &operator=(const MateriaSource &);

	MateriaSource(const MateriaSource &);
};


#endif //CPP_MATERIASOURCE_H
