//
// Created by aurel on 3/26/23.
//

#include "../incs/Brain.h"

using std::cout;
using std::endl;

Brain::Brain()
{
	cout << "Constructor Brain called" << endl;
}

Brain::~Brain()
{
	cout << "Destructor Brain called" << endl;
}

Brain::Brain( const Brain &other )
{
	*this = other;
	cout << "Copy constructor Brain called" << endl;
}

Brain &Brain::operator=( const Brain &other )
{
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	cout << "Constructor assignement Brain called" << endl;
	return *this;
}
