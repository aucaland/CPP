//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
#include "../incs/IMateriaSource.h"
using std::string;


class MateriaSource : public IMateriaSource
{
private:
	AMateria* _materias[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource &operator=(const MateriaSource &);
	MateriaSource(const MateriaSource &);

	AMateria *getMateria(std::string const & type);
	AMateria *createMateria(std::string const & type);
	void 	learnMateria(AMateria *m);
};


#endif //CPP_MATERIASOURCE_H
