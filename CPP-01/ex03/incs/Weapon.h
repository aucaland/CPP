//
// Created by aurel on 3/17/23.
//

#ifndef CPP_WEAPON_H
#define CPP_WEAPON_H

#include <iostream>
using std::string;

class Weapon
{
private :
	string	_type;

public :
	Weapon(string type);
	~Weapon();
	const	string&	getType() const;
	void 	setType(string newType);
};


#endif //CPP_WEAPON_H
