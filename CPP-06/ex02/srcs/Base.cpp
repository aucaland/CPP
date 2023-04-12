//
// Created by aurel on 4/12/23.
//

#include "../incs/Base.h"

using std::cout;
using std::endl;

Base::Base()
{
	cout << "Constructor Base called" << endl;
}

Base::~Base()
{
	cout << "Destructor Base called" << endl;
}

Base::Base( const Base &other )
{
	cout << "Copy constructor Base called" << endl;
}

Base &Base::operator=( const Base &other )
{
	cout << "Copy assignement Base called" << endl;
	return *this;
}
