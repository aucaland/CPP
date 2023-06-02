//
// Created by aurel on 4/11/23.
//

#pragma once

#include <iostream>
#include "AForm.h"
using std::string;


class Intern
{
public:
	Intern();

	~Intern();

	Intern &operator=( const Intern & );

	Intern( const Intern & );

	AForm *makeForm( string formType, string target ) const;
};
