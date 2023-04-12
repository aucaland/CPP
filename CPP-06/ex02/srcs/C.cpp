//
// Created by aurel on 4/12/23.
//

#include "../incs/C.h"

using std::cout;
using std::endl;

C::C()
{
	cout << "Constructor C called" << endl;
}

C::~C()
{
	cout << "Destructor C called" << endl;
}

C::C( const C &other )
{
	cout << "Copy constructor C called" << endl;
}

C &C::operator=( const C &other )
{
	cout << "Copy assignement C called" << endl;
	return *this;
}
