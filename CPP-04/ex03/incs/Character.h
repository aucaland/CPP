//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
#include "AMateria.h"
using std::string;


class Character : public ICharacter
{
protected:

public:
	Character();
	~Character();
	Character (string name);
	Character &operator=(const Character &);
	Character(const Character &);

	string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
	AMateria *_inventory[4];
	string _name;
};

