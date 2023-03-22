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

DiamondTrap::DiamondTrap( const DiamondTrap &other )
{
	cout << "Copy constructor DiamondTrap called" << endl;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other )
{
	cout << "Constructor assignement DiamondTrap called" << endl;
	return *this;
}
