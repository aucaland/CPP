#pragma once

#include <stack>
#include <iostream>
#include <algorithm>

using std::endl;
using std::cout;

template<typename T> class MutantStack : public std::stack<T>
{
public:
	MutantStack() {};
	~MutantStack() {};

	MutantStack &operator=(const MutantStack &other){
		if (this != &other)
			this->c = other.c;
		return *this;
	};
	MutantStack(const MutantStack &other) : std::stack<T>(){
		this->c = other.c;
	};

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); };
	iterator end() { return this->c.end(); };
};