//
// Created by aurel on 4/12/23.
//

#pragma once

#include <iostream>
#include "Base.h"

using std::string;


class B : public Base
{
public:
	B();

	~B();

	B &operator=( const B & );

	B( const B & );
};
