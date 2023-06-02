//
// Created by aurel on 4/8/23.
//

#pragma once

#include <iostream>
#include "AForm.h"
class AForm;
#include <exception>

using std::string;


class Bureaucrat
{
private:
	int				_grade;
	string const	_name;

public:
	Bureaucrat();

	~Bureaucrat();
	Bureaucrat(string const name, int grade);

	Bureaucrat &operator=( const Bureaucrat & );

	Bureaucrat( const Bureaucrat & );

	string const getName() const;
	int		getGrade() const;

	void 			incrementGrade();
	void 			decreamentGrade();

	void signForm( AForm &form );
	void executeForm( AForm const & form );


class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(char * msg);
		virtual ~GradeTooHighException() throw();
		virtual const char* what() const throw();
	private:
		char * High_msg;
	};

class GradeTooLowException : public std::exception
{
	public:
		explicit GradeTooLowException(char * msg);
		virtual ~GradeTooLowException() throw();
		virtual const char* what() const throw();
	private:
		char * Low_msg;
	};
};

//std::ostream & operator<<(std::ostream & out, const Bureaucrat & src);