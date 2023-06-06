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


#define RESET   "\033[0m"
#define GRAY   "\033[47m"      	/* GREY */
#define RED     "\033[4;30;42 m" /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

class Span {
public:
    Span();
    ~Span();
    Span(unsigned int N);
    Span &operator=(const Span &);
    Span(const Span &);

    void 			addNumber( int number );
    int 			shortestSpan();
    int 			longestSpan();

    unsigned int 	getCapacity();

private:
    unsigned int 		_maxCapacity;
    std::vector<int>	_vectorContainer;
};
