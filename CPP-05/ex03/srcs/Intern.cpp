//
// Created by aurel on 4/11/23.
//

#include "../incs/Intern.h"
#include "../incs/ShrubberyCreationForm.h"
#include "../incs/RobotomyRequestForm.h"
#include "../incs/PresidentialPardonForm.h"

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
	*this = other;
	cout << "Copy constructor Intern called" << endl;
}

Intern &Intern::operator=( const Intern &other )
{
	(void) other;
	cout << "Copy assignement Intern called" << endl;
	return *this;
}

AForm *Intern::makeForm( string formType, string target ) const
{
	int i = 0;
	string arrayFormTypes[] = {"Rform", "Pform", "Sform"};

	for (i = 0; i < 3; i++)
		if (arrayFormTypes[i] == formType)
			break;
	switch ( i )
		{
			case 0:
				return (new RobotomyRequestForm( target ));
			case 1:
				return (new PresidentialPardonForm( target ));
			case 2:
				return (new ShrubberyCreationForm( target ));
			default:
				cout << "Intern didn't understand your request, please ask politely : [Rform], [Pform] or [Sform] ?" << endl;
				return NULL;
		}
}
