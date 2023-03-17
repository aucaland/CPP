//
// Created by aurel on 3/17/23.
//

#include "../incs/HumanB.h"
using std::cout;
using std::endl;

HumanB::HumanB(string name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB()
{

}
void HumanB::attack()
{
	if (this->_weapon == NULL)
		cout << this->_name << " doesn't have a _weapon " << endl;
	else
		cout << this->_name << " attacks with " <<
			 this->_weapon->getType() << endl;
}

void HumanB::setWeapon(Weapon& type)
{
	this->_weapon = &type;
}