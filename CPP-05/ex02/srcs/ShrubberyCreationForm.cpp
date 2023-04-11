//
// Created by aurel on 4/10/23.
//

#include "../incs/ShrubberyCreationForm.h"

using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShruberryForm", 145, 137)
{
	cout << "Constructor ShrubberyCreationForm called" << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "Destructor ShrubberyCreationForm called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ) : Form( other )
{
	cout << "Copy constructor ShrubberyCreationForm called" << endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other )
{
	cout << "Copy assignement ShrubberyCreationForm called" << endl;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(string target) : Form("ShruberryForm", 145, 137)
{
	this->_target = target;
}

void ShrubberyCreationForm::createFile(string target)
{
	try
	{
		std::ofstream  file(target + "_shrubbery");
		drawTrees(file);
	}
	catch (std::exception & e)
	{
		cout << e.what() << endl;
	}

}

void ShrubberyCreationForm::drawTrees( std::ofstream &file )
{
	for (int i = 0; i < this->getName().size(); i++)
	{
		for (int j = 0; j < j + i * i; j++)
		{
			file << '*';
		}
	}
}

void ShrubberyCreationForm::beSigned() {

}
