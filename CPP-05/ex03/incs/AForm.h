//
// Created by aurel on 4/9/23.
//

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "Bureaucrat.h"
class Bureaucrat;
using std::string;


class Form
{
private:
	string const _name;
	bool 		_isSigned;
	int const	_gradeSign;
	int const	_gradeExec;
public:
	/* Canonical */

	Form();
	~Form();
	Form &operator=( const Form & );
	Form( const Form & );

	/* Accessors */

	bool getIsSigned() const;
	int getGradSign() const;
	int getGradExec() const;
	string const getName() const;

	/* Form function && other constructors */

	Form( string name, int rankSign, int rankExec );
	void beSigned( Bureaucrat & );

	virtual void	execute(Bureaucrat const & executor) const = 0;

	/* Class exceptions */

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException( char * msg );
		virtual ~GradeTooHighException() throw();
		virtual const char* what() const throw();
	private:
		char * High_msg;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException( char * msg );
		virtual ~GradeTooLowException() throw();
		virtual const char* what() const throw();
	private:
		char * Low_msg;
	};

	class FormNotSigned : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

/* Override operator */

std::ostream  &operator<<(std::ostream &out, const Form &src);
