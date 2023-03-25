//
// Created by aucaland on 3/24/23.
//

#include "../incs/Cat.h"

using std::cout;
using std::endl;

Cat::Cat() {
	this->type = "Cat";
	cout << "Constructor Cat called" << endl;
}

Cat::~Cat() {
	cout << "Destructor Cat called" << endl;
}

Cat::Cat(const Cat &other) : Animal(other), type(other.type)
{
	cout << "Copy constructor Cat called" << endl;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	cout << "Constructor assignement Cat called" << endl;
	return *this;
}

void Cat::makeSound() const
{
	cout << "Miaou" << endl;
}