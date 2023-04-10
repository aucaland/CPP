//
// Created by aurel on 4/10/23.
//

#pragma once

#include <iostream>

using std::string;


class ShrubberyCreationForm
{
public:
	ShrubberyCreationForm();

	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=( const ShrubberyCreationForm & );

	ShrubberyCreationForm( const ShrubberyCreationForm & );
};
