//
// Created by aurel on 3/17/23.
//

#ifndef CPP_HUMANA_H
#define CPP_HUMANA_H

#include "../incs/Weapon.h"
using std::string;
class HumanA
{
public :
	HumanA(string name, Weapon& weapon);
	~HumanA();
	void	attack();
private :
	string _name;
	Weapon& _weapon;

};


#endif //CPP_HUMANA_H
