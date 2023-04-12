//
// Created by aurel on 4/12/23.
//

#pragma once

#include <iostream>
#include "Base.h"

using std::string;


class A : public Base
{
public:
	A();

	~A();

	A &operator=( const A & );

	A( const A & );
};
