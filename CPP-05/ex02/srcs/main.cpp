//
// Created by aurel on 4/8/23.
//
#include "../incs/Bureaucrat.h"
#include "../incs/ShrubberyCreationForm.h"
#include "../incs/RobotomyRequestForm.h"
#include "../incs/PresidentialPardonForm.h"

int main()
{
	try
	{
		ShrubberyCreationForm		Sform("Sform");
		RobotomyRequestForm		Rform("Rform");
		PresidentialPardonForm		Pform("Pform");

		Bureaucrat samy("samy", 130);
		Bureaucrat samy2("samy2", 1);

		samy2.signForm(Sform);
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
}