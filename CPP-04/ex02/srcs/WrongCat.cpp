//
// Created by aucaland on 3/24/23.
//

#include "../incs/WrongCat.h"

using std::cout;
using std::endl;

WrongCat::WrongCat() {
	this->type = "Cat";
	cout << "Constructor WrongCat called" << endl;
}

WrongCat::~WrongCat() {
	cout << "Destructor WrongCat called" << endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other), type(other.type)
{
	cout << "Copy constructor WrongCat called" << endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->type = other.type;
	cout << "Constructor assignement WrongCat called" << endl;
	return *this;
}

void WrongCat::makeSound() const
{
	cout << "Miaou" << endl;
}