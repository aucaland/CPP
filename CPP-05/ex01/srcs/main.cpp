//
// Created by aurel on 4/8/23.
//
#include "../incs/Bureaucrat.h"

int main()
{
	try
	{
//		Bureaucrat empty("creep", 15);
		Form		form("void", 10, 10);
//		empty.incrementGrade();
//		Bureaucrat empty2("creep", 151);
//		Bureaucrat empty3("creep", -10);
		Bureaucrat scooby("scooby", 9);
		Bureaucrat samy("samy", 150);
//		samy.decreamentGrade();
//		Form formOne;
//		samy.signForm(form);
		scooby.signForm( form );
		samy.signForm(form);
//		formOne.beSigned(empty);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

}