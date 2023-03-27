//
// Created by aucaland on 3/27/23.
//

#pragma once

#include <iostream>
using std::string;


class Ice
{
public:
	Ice();

	~Ice();

	Ice &operator=(const Ice &);

	Ice(const Ice &);
	Ice*	clone();
	void 	use(ICharacter&);
};


#endif //CPP_ICE_H
