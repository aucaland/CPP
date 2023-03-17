//
// Created by aurel on 3/17/23.
//

#ifndef CPP_HUMANB_H
#define CPP_HUMANB_H

#include "../incs/Weapon.h"

class HumanB
{
public :
	HumanB(string name);
	~HumanB();
	void	attack();
	void 	setWeapon(Weapon& type);
private :
	string _name;
	Weapon* _weapon;

};


#endif //CPP_HUMANB_H
