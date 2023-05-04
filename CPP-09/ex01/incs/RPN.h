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
	static string const 				validArgs;
	static string const 				operators;
	static string const 				operands;
	string const						_inverted_expression;
	string 								_tmp;
	unsigned int						_numberOfOperand;
	unsigned int						_consecutivOperandCount;
	string 								*_result;
	std::stack<int>						_execStack;
	RPN();
public:
	~RPN();

	RPN &operator=(const RPN &);
	RPN(const RPN &);
	RPN( char *rpnExpression );
	bool ValidArg( char c );
	bool tooMuchConsecutivOperand();
	bool rpnIsValid( char c );
	void rpn( char *rpnExpression );
	bool isOperand( char c );
	bool isOperator( char c);
	bool checkEnd();
	bool tooMuchOperators();
	void performOperation( char c );
};


#endif //CPP_RPN_H
