//
// Created by aurel on 4/10/23.
//

#pragma once

#include <iostream>
#include <fstream>
#include "Form.h"

using std::string;


class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();

	/* Class function and other constructors */

	explicit ShrubberyCreationForm( string target );
	void 	drawTrees( std::ofstream & ) const ;

	/* Override */
	void execute(Bureaucrat const & exec) const;

private:
	string _target;
};