//
// Created by aurel on 4/8/23.
//
#include "../incs/Bureaucrat.h"
#include "../incs/ShrubberyCreationForm.h"
int main()
{
	try
	{
//		Bureaucrat empty("creep", 15);
		ShrubberyCreationForm		form("void");
//		empty.incrementGrade();
//		Bureaucrat empty2("creep", 151);
//		Bureaucrat empty3("creep", -10);
		Bureaucrat samy("samy", 150);
//		samy.decreamentGrade();
//		Form formOne;
//		samy.signForm(form);
		samy.signForm(form);
//		formOne.beSigned(empty);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

}