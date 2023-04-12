//
// Created by aurel on 4/12/23.
//

#pragma once

#include <iostream>
#include "Base.h"

using std::string;


class C : public Base
{
public:
	C();

	~C();

	C &operator=( const C & );

	C( const C & );
};
