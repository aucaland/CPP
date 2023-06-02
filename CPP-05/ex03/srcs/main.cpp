//
// Created by aurel on 4/8/23.
//
#include "../incs/Bureaucrat.h"
#include "../incs/ShrubberyCreationForm.h"
#include "../incs/RobotomyRequestForm.h"
#include "../incs/PresidentialPardonForm.h"
#include "../incs/Intern.h"

int main()
{
	AForm *internForm = NULL;

	try
	{
		Intern					internSlave;

		ShrubberyCreationForm		Sform("Sform");
		RobotomyRequestForm		Rform("target");
		PresidentialPardonForm		Pform("Pform");
		internForm = internSlave.makeForm( "Pform", "Intern");
		Bureaucrat samy("Samy", 1);
		Bureaucrat samy2("Samy2", 1);
		Bureaucrat samy3("Samy3", 1);

		samy2.signForm(Sform);
		samy3.signForm(*internForm);
		samy3.executeForm(*internForm);
		samy2.signForm(Rform);
		samy2.signForm(Pform);
		samy.signForm(Rform);
		samy2.executeForm( Rform );
		samy.executeForm( Rform );
		samy.executeForm( Sform );
		samy2.executeForm(Pform);
		samy.executeForm(Pform);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	if ( internForm )
		delete internForm;
}