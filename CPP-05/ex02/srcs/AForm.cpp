//
// Created by aurel on 4/9/23.
//

#include <cstring>
#include "../incs/AForm.h"


using std::cout;
using std::endl;

AForm::AForm() : _name("Default"), _isSigned(false), _gradeSign(5), _gradeExec(10)
{
	cout << "Constructor AForm called" << endl;
}

AForm::~AForm()
{
	cout << "Destructor AForm called" << endl;
}

AForm::AForm( const AForm &other ) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
	cout << "Copy constructor AForm called" << endl;
}

AForm &AForm::operator=( const AForm &other )
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	cout << "Copy assignement AForm called" << endl;
	return *this;
}

const string AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

int AForm::getGradSign() const
{
	return this->_gradeSign;
}

int AForm::getGradExec() const
{
	return this->_gradeExec;
}

void AForm::beSigned( Bureaucrat &src )
{
	if ( src.getGrade() <= this->_gradeSign )
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

AForm::AForm( const string name, const int rankSign, const int rankExec ) : _name(name), _gradeSign(rankSign), _gradeExec(rankExec)
{
	if (rankSign < 1 || rankExec < 1) {
		throw GradeTooHighException((char *)"Rank too High");
	}
	if (rankSign > 150 || rankExec > 150) {
		throw GradeTooLowException( );
	}
}

AForm::GradeTooHighException::GradeTooHighException( char *msg )
{
	this->High_msg = msg;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Rank is too low to sign Form";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return this->High_msg;
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{

}

std::ostream &operator<<(std::ostream &out, const AForm &src) {
	string isSigned = ". AForm is signed";
	if (!src.getIsSigned())
		isSigned = ". AForm is not signed";
	out << "AForm name : " << src.getName() << ". Rank required to sign : " << src.getGradSign();
	out << ", Rank required to execute : " << src.getGradExec() << isSigned << endl;

	return out;
}

const char *AForm::FormNotSigned::what() const throw()
{
	return "AForm is not signed";
}