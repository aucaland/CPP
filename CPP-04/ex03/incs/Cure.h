//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
using std::string;


class Cure
{
public:
	Cure();

	~Cure();

	Cure &operator=(const Cure &);

	Cure(const Cure &);
	Cure*	clone();
	void 	use(ICharacter&);
};


#endif //CPP_CURE_H
