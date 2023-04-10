//
// Created by aurel on 4/8/23.
//
#include "../incs/Bureaucrat.h"

int main()
{
	try
	{
		Bureaucrat empty("creep", 0);
		std::cout << empty << std::endl;
//		empty.incrementGrade();
//		Bureaucrat empty2("creep", 151);
//		Bureaucrat empty3("creep", -10);
		Bureaucrat samy("samy", 150);
		samy.decreamentGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

}