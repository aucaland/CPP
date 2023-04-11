//
// Created by aurel on 4/11/23.
//

#include "Intern.h"

using std::cout;
using std::endl;

Intern::Intern()
{
	cout << "Constructor Intern called" << endl;
}

Intern::~Intern()
{
	cout << "Destructor Intern called" << endl;
}

Intern::Intern( const Intern &other )
{
	cout << "Copy constructor Intern called" << endl;
}

Intern &Intern::operator=( const Intern &other )
{
	cout << "Copy assignement Intern called" << endl;
	return *this;
}
