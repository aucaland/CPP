//
// Created by aurel on 4/10/23.
//

#pragma once

#include <iostream>

using std::string;


class RobotomyRequestForm
{
public:
	RobotomyRequestForm();

	~RobotomyRequestForm();

	RobotomyRequestForm &operator=( const RobotomyRequestForm & );

	RobotomyRequestForm( const RobotomyRequestForm & );
};
