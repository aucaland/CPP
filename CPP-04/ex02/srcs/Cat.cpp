//
// Created by aucaland on 3/24/23.
//

#include "../incs/Cat.h"
#include "../incs/Brain.h"

using std::cout;
using std::endl;

Cat::Cat() {
	cout << "Constructor Cat called" << endl;
	this->_brain = new Brain();
	this->_type = "Cat";

}

Cat::~Cat() {
	delete this->_brain;
	cout << "Destructor Cat called" << endl;
}

Cat::Cat(const Cat &other) : Animal()
{
	this->_brain = new Brain(*other._brain);
	this->_type = other.getType();
	cout << "Copy constructor Cat called" << endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	this->_type = other._type;
	cout << "Copy assignement Cat called" << endl;
	return *this;
}

Animal &Cat::operator=( const Animal & other ) {
	if (this == &other)
		return *this;
	delete this->_brain;
	this->_brain = new Brain(*other.getBrain());
	this->_type = other.getType();
	cout << "Copy assignement Animal called from Dog" << endl;
	return *this;
}

void Cat::makeSound() const
{
	cout << "Miaou" << endl;
}

Brain *Cat::getBrain() const
{
	return this->_brain;
}
