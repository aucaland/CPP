//
// Created by aurel on 4/10/23.
//

#pragma once

#include <iostream>
#include <fstream>
#include "../incs/Form.h"

using std::string;


class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();

	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=( const ShrubberyCreationForm & );

	ShrubberyCreationForm( const ShrubberyCreationForm & );

	/* Functions and other constructors */
	explicit ShrubberyCreationForm( string target );
	void 	createFile( string target );
	void 	drawTrees( std::ofstream & );

	/* Override */
	void 	beSigned();

private:
	string _target;
};
