//
// Created by aurel on 4/10/23.
//

#include "../incs/ShrubberyCreationForm.h"

using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShruberryForm", 145, 137)
{
	cout << "Constructor ShrubberyCreationForm called" << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "Destructor ShrubberyCreationForm called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm("ShruberryForm", 145, 137)
{
	this->_target = target;
}

void ShrubberyCreationForm::execute( const Bureaucrat &exec ) const
{
	if (!this->getIsSigned())
		throw FormNotSigned();
	else if (exec.getGrade() > this->getGradExec())
		throw GradeTooLowException( );
	string filename = this->_target + "_shrubbery";
	std::ofstream  file(filename.c_str());
	if (!file.is_open())
	{
		std::perror(filename.c_str());
		return ;
	}
	drawTrees(file);
}

void ShrubberyCreationForm::drawTrees( std::ofstream &file ) const
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20 - i; j++) {
			file << " ";
		}
		for (int j = 0; j < i * 2 + 1; j++) {
			file << "*";
		}
		file << endl;
	}

	for (int i = 0; i < 20 / 2; i++) {
		for (int j = 0; j < 20 - 1; j++) {
			file << " ";
		}
		file << "*";
		file << endl;
	}
	file.close();
}