//
// Created by aurel on 4/9/23.
//

#include <cstring>
#include "../incs/AForm.h"

using std::cout;
using std::endl;

Form::Form() : _name("Default"), _isSigned(false), _gradeSign(5), _gradeExec(10)
{
	cout << "Constructor Form called" << endl;
}

Form::~Form()
{
	cout << "Destructor Form called" << endl;
}

Form::Form( const Form &other ) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
	cout << "Copy constructor Form called" << endl;
}

Form &Form::operator=( const Form &other )
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	cout << "Copy assignement Form called" << endl;
	return *this;
}

const string Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getGradSign() const
{
	return this->_gradeSign;
}

int Form::getGradExec() const
{
	return this->_gradeExec;
}

void Form::beSigned( Bureaucrat &src )
{
	if ( src.getGrade() <= this->_gradeSign )
		this->_isSigned = true;
	else
	{
		int num = src.getGrade();
		std::stringstream rank;
		rank << num;
		int numTwo = this->_gradeSign;
		std::stringstream rankSign;
		rankSign << numTwo;
		std::string Rank = rank.str();
		std::string RankSign = rankSign.str();
		string message = "Bureaucrat " + src.getName() + " of Rank " + Rank +
									   " need to be rank " + RankSign + " to sign the '" + this->_name + "' form.";
		char msg[100];
		msg[99] = '\0';
		std::strcpy(msg, message.c_str());
		throw GradeTooLowException(msg);
	}
}

Form::Form( const string name, const int rankSign, const int rankExec ) : _name(name), _gradeSign(rankSign), _gradeExec(rankExec)
{
	if (rankSign < 1 || rankExec < 1) {
		throw GradeTooHighException((char *)"Rank too High");
	}
	if (rankSign > 150 || rankExec > 150) {
		throw GradeTooLowException((char *)"Rank too low");
	}
}

Form::GradeTooLowException::GradeTooLowException( char *msg )
{
	this->Low_msg = msg;
}

Form::GradeTooHighException::GradeTooHighException( char *msg )
{
	this->High_msg = msg;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return this->Low_msg;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return this->High_msg;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{

}

Form::GradeTooHighException::~GradeTooHighException() throw()
{

}

std::ostream &operator<<(std::ostream &out, const Form &src) {
	string isSigned = ". Form is signed";
	if (!src.getIsSigned())
		isSigned = ". Form is not signed";
	out << "Form name : " << src.getName() << ". Rank required to sign : " << src.getGradSign();
	out << ", Rank required to execute : " << src.getGradExec() << isSigned << endl;

	return out;
}

const char *Form::FormNotSigned::what() const throw()
{
	return "Form is not signed";
}