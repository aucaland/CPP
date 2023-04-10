//
// Created by aurel on 4/10/23.
//

#pragma once

#include <iostream>

using std::string;


class PresidentialPardonForm
{
public:
	PresidentialPardonForm();

	~PresidentialPardonForm();

	PresidentialPardonForm &operator=( const PresidentialPardonForm & );

	PresidentialPardonForm( const PresidentialPardonForm & );
};
