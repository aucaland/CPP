//
// Created by aurel on 4/10/23.
//

#include "../incs/PresidentialPardonForm.h"

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm() : Form( "PresidentialPardonForm", 25, 5)
{
	cout << "Constructor PresidentialPardonForm called" << endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "Destructor PresidentialPardonForm called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm( string target ) : Form( "PresidentialPardonForm", 25, 5)
{
	this->_target = target;
}

void PresidentialPardonForm::execute( const Bureaucrat &exec ) const
{
	if (!this->getIsSigned())
		throw FormNotSigned();
	else if (exec.getGrade() > this->getGradExec())
		throw GradeTooLowException((char *)"Grade too low for exec PresidentialPardonForm");
	cout << this->_target << " has been excuse by Zaphod Beeblebrox" << endl;

}