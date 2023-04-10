//
// Created by aurel on 4/10/23.
//

#include "PresidentialPardonForm.h"

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm()
{
	cout << "Constructor PresidentialPardonForm called" << endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "Destructor PresidentialPardonForm called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(
		const PresidentialPardonForm &other )
{
	cout << "Copy constructor PresidentialPardonForm called" << endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=( const PresidentialPardonForm &other )
{
	cout << "Copy assignement PresidentialPardonForm called" << endl;
	return *this;
}
