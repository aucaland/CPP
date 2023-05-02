//
// Created by aucaland on 5/2/23.
//

#include "../incs/RPN.h"

using std::cout;
using std::endl;

RPN::RPN() {
	cout << "Constructor RPN called" << endl;
}

RPN::~RPN() {
	cout << "Destructor RPN called" << endl;
}

RPN::RPN(const RPN &other) {
	cout << "Copy constructor RPN called" << endl;
}

RPN &RPN::operator=(const RPN &other) {
	cout << "Constructor assignement RPN called" << endl;
	return *this;
}

bool RPN::checkValidArg() {

	return false;
}

bool RPN::checkConsecutivNumberArg() {
	return false;
}
