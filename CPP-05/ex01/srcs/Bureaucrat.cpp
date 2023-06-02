//
// Created by aurel on 4/8/23.
//

#include "../incs/Bureaucrat.h"


using std::cout;
using std::endl;

Bureaucrat::Bureaucrat() : _grade(150), _name("clone")
{
	cout << "Constructor Bureaucrat called" << endl;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Destructor Bureaucrat named : " << this->_name << " , Rank : " << this->_grade << " called" << endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) : _grade(other._grade), _name(other._name)
{
	cout << "Copy constructor Bureaucrat called" << endl;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other )
{
	if (this != &other)
	{
		this->_grade = other.getGrade();
	}
	cout << "Copy assignement Bureaucrat called" << endl;
	return *this;
}

Bureaucrat::Bureaucrat( const string name, int grade ) : _grade(grade), _name(name)
{
	cout << "Constructor (string, int) called, name :" << this->_name << ", Rank : " << this->_grade << endl;
	if (this->_grade > 150)
		throw GradeTooLowException((char *)"Min rank is 150");
	else if (this->_grade < 1)
		throw GradeTooHighException((char *)"Max rank is 1");
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException((char *)"Rank is 1, which is max");
	else
		this->_grade--;
}

void Bureaucrat::decreamentGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException((char *)"Rank is 150, which is min");
	else
		this->_grade++;
}

string const Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

Bureaucrat::GradeTooLowException::GradeTooLowException( char * msg )
{
	this->Low_msg = msg;
}

Bureaucrat::GradeTooHighException::GradeTooHighException( char * msg )
{
	this->High_msg = msg;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->High_msg;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->Low_msg;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{

}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{

}

void Bureaucrat::signForm( Form &form )
{
	try {
		form.beSigned(*this);
		cout << this->getName() << " signed " << form.getName() << endl;
	}
	catch (std::exception &e) {
		cout << this->getName() << " couldn't sign " << form.getName() <<
				  " because: " << e.what() << endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return out;
}
