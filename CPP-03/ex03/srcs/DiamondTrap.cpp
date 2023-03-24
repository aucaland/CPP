//
// Created by aurel on 3/22/23.
//

#include "../incs/DiamondTrap.h"

using std::cout;
using std::endl;

DiamondTrap::DiamondTrap()
{
	cout << "Constructor \033[1m\033[32mDiamondTrap\033[0m\033[0m called" << endl;
}

DiamondTrap::~DiamondTrap()
{
	cout << "Destructor \033[1m\033[32mDiamondTrap\033[0m\033[0m called" << endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap( other ), FragTrap( other ), ScavTrap( other )
{
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
	cout << "Copy constructor \033[1m\033[32mDiamondTrap\033[0m\033[0m called" << endl;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other )
{
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
	cout << "Constructor assignement \033[1m\033[32mDiamondTrap\033[0m\033[0m called" << endl;
	return *this;
}

DiamondTrap::DiamondTrap( string name ) : ClapTrap( name + "_clap_name" )
{
	this->_name = name;
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = FragTrap::_attackDamage;
	cout << "\033[1m\033[32mDiamondTrap\033[0m\033[0m [ " << this->_name << " ] constructor called" << endl;

}

void DiamondTrap::attack( const string & target )
{
	ScavTrap::attack( target );
}

void DiamondTrap::whoAmI()
{
	cout << "I am a \033[1m\033[32mDiamondTrap\033[0m\033[0m called " << this->_name << ", my grand-mother \033[1m\033[32mClapTrap\033[0m\033[0m is called " << ClapTrap::_name << endl;
}
