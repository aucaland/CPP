//
// Created by aurel on 3/22/23.
//

#include "../incs/DiamondTrap.h"

using std::cout;
using std::endl;

DiamondTrap::DiamondTrap()
{
	cout << "Constructor DiamondTrap called" << endl;
}

DiamondTrap::~DiamondTrap()
{
	cout << "Destructor DiamondTrap called" << endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap( other ), FragTrap( other ), ScavTrap( other )
{
	*this = other;
	cout << "Copy constructor DiamondTrap called" << endl;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other )
{
	(void) other;

	cout << "Constructor assignement DiamondTrap called" << endl;
	return *this;
}

DiamondTrap::DiamondTrap( string name ) : ClapTrap( name + "_clap_name" )
{
	this->_name = name;
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = FragTrap::_attackDamage;
	cout << "DiamondTrap [ " << this->_name << " ] constructor called" << endl;

}

void DiamondTrap::attack( const string & target )
{
	ScavTrap::attack( target );
}
