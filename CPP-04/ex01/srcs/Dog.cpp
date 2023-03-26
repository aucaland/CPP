//
// Created by aucaland on 3/24/23.
//

#include "../incs/Dog.h"


using std::cout;
using std::endl;

Dog::Dog()
{
	cout << "Constructor Dog called" << endl;
	this->_brain = new Brain();
	this->_type = "Dog";
}

Dog::~Dog() {
	delete this->_brain;
	cout << "Destructor Dog called" << endl;
}

Dog::Dog(const Dog &other) : Animal()
{
	this->_brain = new Brain();
	this->_type = other.getType();
	cout << "Copy constructor Dog called" << endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this == &other)
		return *this;
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	this->_type = other._type;
	cout << "Copy assignement Dog called" << endl;
	return *this;
}

Animal &Dog::operator=( const Animal & other ) {
	if (this == &other)
		return *this;
	delete this->_brain;
	this->_brain = new Brain(*other.getBrain());
	this->_type = other.getType();
	cout << "Copy assignement Animal called from Dog" << endl;
	return *this;
}

void Dog::makeSound() const
{
	cout << "Wouf" << endl;
}

Brain* Dog::getBrain() const
{
	return this->_brain;
}
