//
// Created by aurel on 4/10/23.
//

#pragma once

#include <iostream>
#include "Form.h"
using std::string;


class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();

	/* Class function and other constructors */

	explicit PresidentialPardonForm( string target );

	/* Override */

	void execute(Bureaucrat const & exec) const;

private:
	string _target;
};
