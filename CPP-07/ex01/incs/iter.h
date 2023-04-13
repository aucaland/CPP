//
// Created by aurel on 4/13/23.
//

#pragma once

#include <iostream>
using std::cout;
using std::endl;

template<typename T> void printElem(T elem)
{
	cout << elem << std::flush;
}

template <typename T, typename V> void iter(T *arr, unsigned int length, V func)
{
	for ( unsigned int i = 0; i < length; ++i )
	{
		func(arr[i]);
	}
	cout << endl;
}