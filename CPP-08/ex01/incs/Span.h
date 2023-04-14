//
// Created by aurel on 4/14/23.
//

#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

using std::string;


class Span {
public:
    Span();
    ~Span();

    Span(unsigned int N);
    Span &operator=(const Span &);
    Span(const Span &);

    void addNumber( int number );
    int shortestSpan();
    int longestSpan();

    unsigned int getCapacity();
private:
    unsigned int _maxCapacity;
    std::vector<int> _vectorContainer;
};
