//
// Created by aurel on 3/17/23.
//

#include "../incs/Weapon.h"

Weapon::Weapon(string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{

}

void Weapon::setType(string newType)
{
	this->_type = newType;
}

const string& Weapon::getType() const
{
	return (this->_type);
}