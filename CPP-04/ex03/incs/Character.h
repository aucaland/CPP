//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
#include "../incs/ICharacter.h"
using std::string;


class Character : public ICharacter
{
protected:

public:
	Character();

	~Character();

	Character &operator=(const Character &);

	Character(const Character &);
};

#endif //CPP_CHARACTER_H
