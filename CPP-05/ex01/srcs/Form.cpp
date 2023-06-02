//
// Created by aurel on 4/9/23.
//

#include <cstring>
#include "../incs/Form.h"

using std::cout;
using std::endl;

Form::Form() : _name("Default"), _isSigned(false), _gradeSign(5),
_gradeExec(10)
{
	cout << "Constructor Form called" << endl;
}

Form::~Form()
{
	cout << "Destructor Form called" << endl;
}

Form::Form( const Form &other ) : _name(other._name), _isSigned(other
																	   ._isSigned),
_gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
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
		throw GradeTooLowException( );
	}
}

Form::Form( const string name, const int rankSign, const int rankExec ) :
		_name
																		   (name), _gradeSign(rankSign), _gradeExec(rankExec)
{

}

Form::GradeTooHighException::GradeTooHighException( char *msg )
{
	this->High_msg = msg;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Rank is too low to sign Form";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return this->High_msg;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{

}

std::ostream &operator<<(std::ostream &out, const Form &src) {
	string isSigned = ". Form is signed";
	if (!src.getIsSigned())
		isSigned = ". Form is not signed";
	out << "Form name : " << src.getName() << ". Rank required to sign : " <<
		src.getGradSign();
	out << ", Rank required to execute : " << src.getGradExec() << isSigned << endl;
	return out;
}
