#pragma once
#include <algorithm>
#include <exception>
#include <iostream>
using std::endl;
using std::cout;

template<typename T> typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return it;
    throw std::runtime_error("Value not found in the container");
}