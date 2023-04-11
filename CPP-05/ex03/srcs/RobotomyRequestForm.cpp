//
// Created by aurel on 4/10/23.
//

#include "../incs/RobotomyRequestForm.h"

using std::cout;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm() : Form( "Default", 72, 45)
{
	cout << "Constructor RobotomyRequestForm called" << endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "Destructor RobotomyRequestForm called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm( string target ) : Form( "RobotomyForm", 72, 45)
{
	this->_target = target;
}

void RobotomyRequestForm::execute( const Bureaucrat &exec ) const
{
	if (!this->getIsSigned())
		throw FormNotSigned();
	else if (exec.getGrade() > this->getGradExec())
		throw GradeTooLowException((char *)"Grade too low for exec RobotomyRequestForm");
	static int i;
	if (i % 2 == 0)
		cout << "* Drill in action * --> Robotomy in progress on " << this->_target << endl;
	else
		cout << this->_target << "'s Robotomy failed" << endl;

}