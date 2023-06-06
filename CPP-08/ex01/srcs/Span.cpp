//
// Created by aurel on 4/14/23.
//

#include "../incs/Span.h"
#include <istream>

using std::cout;
using std::endl;

Span::Span() : _maxCapacity(1){
}

Span::~Span() {
}

Span::Span(const Span &other) : _maxCapacity(other._maxCapacity), _vectorContainer(other._vectorContainer){
}

Span &Span::operator=(const Span &other) {
    if (this != &other)
    {
        this->_maxCapacity = other._maxCapacity;
        this->_vectorContainer = other._vectorContainer;
    }
    return *this;
}

Span::Span(unsigned int N) {
    this->_maxCapacity = N;
}

int Span::longestSpan(){
    if (this->_vectorContainer.size() > 1)
    {
        std::sort(this->_vectorContainer.begin(), this->_vectorContainer.end());
        return this->_vectorContainer.back() - this->_vectorContainer.front();
    }
    throw std::runtime_error("Vector size is <= 1\n");
}

int Span::shortestSpan() {
    if (this->_vectorContainer.size() > 1)
    {
        std::sort(this->_vectorContainer.begin(), this->_vectorContainer.end());
        std::vector<int>::iterator it;
        std::vector<int>::iterator max_it = std::max_element(this->_vectorContainer.begin(), this->_vectorContainer.end());
        std::vector<int>::iterator min_it = std::min_element(this->_vectorContainer.begin(), this->_vectorContainer.end());
        int shortestWay = *max_it - *min_it;
        int range = 0;
        for ( it = this->_vectorContainer.begin(); it != this->_vectorContainer.end() - 1 ; it++) {
            {
                range = *(it + 1) - *it;
                shortestWay = (shortestWay > range) ? range : shortestWay;
            }
        }
        return shortestWay;

    }
    throw std::runtime_error("Vector size is <= 1\n");
}

void Span::addNumber(int number) {
    if (this->_maxCapacity == this->_vectorContainer.size())
        throw std::runtime_error("Vector Max capacity is reached");
    this->_vectorContainer.push_back( number );
}

unsigned int Span::getCapacity() {
    return this->_maxCapacity;
}
