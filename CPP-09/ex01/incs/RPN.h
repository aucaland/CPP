//
// Created by aucaland on 5/2/23.
//

#pragma once

#include <iostream>
#include <deque>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class RPN
{
private:
	static string const 				validArgs;
	static string const 				operators;
	static string const 				operands;
	string const						_inverted_expression;
	unsigned int						_consecutivOperandCount;
	unsigned int						_numberOfOperand;
	string 								_result;
	std::stack<int>						_execStack;

	RPN();

public:
	~RPN();

	RPN &operator=(const RPN &);
	RPN(const RPN &);
	explicit RPN( char *rpnExpression );

	void rpn( char *rpnExpression );
	void performOperation( char c );

	bool ValidArg( char c );
	bool tooMuchConsecutivOperand();
	bool rpnIsValid( char c );
	bool isOperand( char c );
	bool isOperator( char c );
	bool checkEnd();
	bool tooMuchOperators();

	string  getResult() const;
};
