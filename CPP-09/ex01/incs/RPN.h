//
// Created by aucaland on 5/2/23.
//

#pragma once

#include <iostream>
#include <deque>
#include <stack>

using std::string;


class RPN
{
private:
	string const						_inverted_expression;
	int 								_tmp;
	unsigned int						_consecutivIdenticalArgCount;
	std::stack<int, std::deque<int> >	_execStack;
	RPN();
public:
	~RPN();

	RPN &operator=(const RPN &);
	RPN(const RPN &);
	bool checkValidArg();
	bool checkConsecutivNumberArg();
};


#endif //CPP_RPN_H
