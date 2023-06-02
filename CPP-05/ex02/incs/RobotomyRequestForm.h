//
// Created by aurel on 4/10/23.
//

#pragma once

#include <iostream>
#include "../incs/AForm.h"

using std::string;


class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();

	~RobotomyRequestForm();

	/* Class functions and other constructors */

	explicit RobotomyRequestForm( string target );

	/* override */

	void execute( Bureaucrat const & exec ) const;
private:
	string _target;
};
