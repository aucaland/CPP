//
// Created by aucaland on 3/27/23.
//

#include "../incs/Character.h"

using std::cout;
using std::endl;

Character::Character() : _name("Michel"){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	cout << "Constructor Character called" << endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	cout << "Destructor Character called" << endl;
}

Character::Character(const Character &other) : _name(other._name){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = other._inventory[i]->clone();
	cout << "Copy constructor Character called" << endl;
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++) {
			this->_inventory[i] = other._inventory[i]->clone();
		}
	}
	cout << "Constructor assignement Character called" << endl;
	return *this;
}

Character::Character( string name ) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

void Character::equip( AMateria *m )
{
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return ;
		}
	}
	delete m;
	cout << "Inventory is full, bye little Materia" << endl;
}

string const &Character::getName() const
{
	return this->_name;
}

void Character::unequip( int idx )
{
	if (this->_inventory[idx] != NULL)
	{
		this->_inventory[idx] = NULL;
		cout << this->_name << "'s Materia " << this->_inventory[idx]->getType() << " nbr " << idx << " unequipped" << endl;
	}
	else {
		cout << this->_name << " cannot unequip Materia " << this->_inventory[idx]->getType() << " nbr " << idx << endl;
	}
}

void Character::use( int idx, ICharacter &target )
{
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}
