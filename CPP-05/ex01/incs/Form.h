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
	Form();

	~Form();

	Form &operator=( const Form & );

	Form( const Form & );

	string const getName() const;
	Form( string const name, int const rankSign, int const rankExec );
	bool getIsSigned() const;
	int getGradSign() const;
	int getGradExec() const;

	void beSigned( Bureaucrat & );
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
		virtual const char* what() const throw();
	private:
		char * Low_msg;
	};
};

std::ostream  &operator<<(std::ostream &out, const Form &src);
