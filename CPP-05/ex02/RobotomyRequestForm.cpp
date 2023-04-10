//
// Created by aurel on 4/10/23.
//

#include "RobotomyRequestForm.h"

using std::cout;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm()
{
	cout << "Constructor RobotomyRequestForm called" << endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "Destructor RobotomyRequestForm called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other )
{
	cout << "Copy constructor RobotomyRequestForm called" << endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=( const RobotomyRequestForm &other )
{
	cout << "Copy assignement RobotomyRequestForm called" << endl;
	return *this;
}
