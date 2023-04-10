//
// Created by aurel on 4/10/23.
//

#include "ShrubberyCreationForm.h"

using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm()
{
	cout << "Constructor ShrubberyCreationForm called" << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "Destructor ShrubberyCreationForm called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(
		const ShrubberyCreationForm &other )
{
	cout << "Copy constructor ShrubberyCreationForm called" << endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other )
{
	cout << "Copy assignement ShrubberyCreationForm called" << endl;
	return *this;
}
