//
// Created by aurel on 4/13/23.
//

#pragma once
#include <iostream>
#include <typeinfo>
#include <exception>
#include <cstdlib>
using std::endl;
using std::cout;

#define RESET   "\033[0m"
#define GRAY   "\033[47m"      /* GREY */
#define RED     "\033[4;30;42 m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

template <class T> class Array
{
public:
	Array() : _array(new T()), _arraySize(0) {};
	explicit Array( unsigned int n ) : _array(new T[n]), _arraySize(n) {
	};

	~Array(){
		delete [] this->_array;
	}
	/* Copy constructor */

	Array( Array const & other) : _arraySize(other._arraySize) {
		this->_array = new T[_arraySize];
		for ( unsigned int i = 0; i < _arraySize; ++i )
			this->_array[i] = other._array[i];
	};
	/* Copy assignement */

	Array & operator=(Array const & other) {
		if (this != &other)
		{
			this->_arraySize = other._arraySize;
			delete this->_array;
			this->_array = new T[_arraySize];
			for ( unsigned int i = 0; i < _arraySize; ++i )
				this->_array[i] = other._array[i];
		}
		return *this;
	};
	/* Operator overload */

	T & operator[](unsigned int index) const{
		if (index >= this->_arraySize)
			throw std::out_of_range("Index is out of range");
		return this->_array[index];
	};
	/* Accessors */

	unsigned int size() const{
		return _arraySize;
	};

private:
	T *_array;
	unsigned int _arraySize;
};

template<typename T>std::ostream & operator<<(std::ostream & os, const Array<T> &src){
	for ( unsigned int i = 0; i < src.size(); ++i )
	{
		os << "array<" << typeid(T).name()[0] <<
			">[" << i << "] = " << src[i] << endl;
	}
	return os;
}
