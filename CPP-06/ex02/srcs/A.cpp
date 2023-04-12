//
// Created by aurel on 4/12/23.
//

#include "../incs/A.h"

using std::cout;
using std::endl;

A::A()
{
	cout << "Constructor A called" << endl;
}

A::~A()
{
	cout << "Destructor A called" << endl;
}

A::A( const A &other )
{
	cout << "Copy constructor A called" << endl;
}

A &A::operator=( const A &other )
{
	cout << "Copy assignement A called" << endl;
	return *this;
}
