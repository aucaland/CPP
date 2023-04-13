//
// Created by aurel on 4/12/23.
//

#pragma once

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Base
{
public:
	virtual ~Base() {};
};

Base * generate(void);
void identify(Base *p);
void identify(Base &p);