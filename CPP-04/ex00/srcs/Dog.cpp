//
// Created by aucaland on 3/24/23.
//

#include "../incs/Dog.h"

using std::cout;
using std::endl;

Dog::Dog()
{
	this->type = "Dog";
	cout << "Constructor Dog called" << endl;
}

Dog::~Dog() {
	cout << "Destructor Dog called" << endl;
}

Dog::Dog(const Dog &other) : Animal(other), type(other.type)
{
	cout << "Copy constructor Dog called" << endl;
}

Dog &Dog::operator=(const Dog &other) {
	this->type = other.type;
	cout << "Constructor assignement Dog called" << endl;
	return *this;
}

void Dog::makeSound() const
{
	cout << "Wouf" << endl;
}
