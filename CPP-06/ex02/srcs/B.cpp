//
// Created by aurel on 4/12/23.
//

#include "../incs/B.h"

using std::cout;
using std::endl;

B::B()
{
	cout << "Constructor B called" << endl;
}

B::~B()
{
	cout << "Destructor B called" << endl;
}

B::B( const B &other )
{
	cout << "Copy constructor B called" << endl;
}

B &B::operator=( const B &other )
{
	cout << "Copy assignement B called" << endl;
	return *this;
}
