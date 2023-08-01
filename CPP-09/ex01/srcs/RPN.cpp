//
// Created by aucaland on 5/2/23.
//

#include "../incs/RPN.h"

using std::cout;
using std::endl;

const string RPN::validArgs = "*/+-0123456789";
const string RPN::operands = "0123456789";
const string RPN::operators = "*/+-";

RPN::RPN() { // TODO: init value
	cout << "Constructor RPN called" << endl;
}

RPN::~RPN() {
	cout << "Destructor RPN called" << endl;
}

RPN::RPN(const RPN &other) {
	this->_result = other._result;
	this->_execStack = other._execStack;
	this->_consecutivOperandCount = other._consecutivOperandCount;
	this->_numberOfOperand = other._numberOfOperand;
	cout << "Copy constructor RPN called" << endl;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
	{
		this->_result = other._result;
		this->_execStack = other._execStack;
		this->_consecutivOperandCount = other._consecutivOperandCount;
		this->_numberOfOperand = other._numberOfOperand;
	}
	cout << "Constructor assignement RPN called" << endl;
	return *this;
}

bool RPN::ValidArg( char c ) {
	if ( validArgs.find( c ) != string::npos )
		return true;
	return false;
}

//bool RPN::tooMuchConsecutivOperand() {
//	if (++this->_consecutivOperandCount > this->_finalNumberOperators + 1)
//		throw std::runtime_error("-Wrong Expression: One operator is always linked by two expression ('1 2 +' or '1 2 + 2 +' are valid, '1 2 + +' is not)");
//	return false;
//}

bool RPN::rpnIsValid( char c )
{
	if (!ValidArg( c ))
	{
		cout << "Invalid arguments, allowed: '+-*/0123456789'" << endl;
		return false;
	}
	return true;
}

RPN::RPN( char *rpnExpression ) : _consecutivOperandCount(0), _numberOfOperand(0),  _finalNumberOperands(0),_finalNumberOperators(0), _result("")
{
	cout << "RPN char * constructor called with : '" << rpnExpression << "'" << endl;
	rpn(rpnExpression);
}

void RPN::rpn( char *rpnExpression )
{
	string rpnStringExpression(rpnExpression);
	if (rpnStringExpression.empty())
	{
		cout << "Arg is empty" << endl;
		return ;
	}
	string::iterator it;
	for (it = rpnStringExpression.begin(); it != rpnStringExpression.end(); it++)
	{
		while( it != rpnStringExpression.end() && *it == ' ' )
			it++;
		if ((it == rpnStringExpression.end() && checkEnd()) || !rpnIsValid( *it ))
			return ;
		if (isOperand( *it ))//&& !tooMuchConsecutivOperand() ))
			_execStack.push( *it - 48 );
		else if (isOperator( *it ) && !tooMuchOperators())
		{
			std::stringstream ss;

			performOperation( *it );
			ss << this->_execStack.top();
			this->_result = ss.str();
		}
	}
}

bool RPN::isOperand( char c )
{
	if (operands.find(c) != string::npos)
	{
		this->_finalNumberOperands++;
		this->_numberOfOperand++;
		return true;
	}
	return false;
}

bool RPN::isOperator( char c )
{
	if (operators.find(c) != string::npos)
	{
		this->_finalNumberOperators++;
		this->_consecutivOperandCount--;
		return true;
	}
	return false;
}

bool RPN::checkEnd()
{
	if(this->_result.empty())
	{
		cout << "Wrong expression" << endl;
		return false;
	}
	return true;
}

bool RPN::tooMuchOperators()
{
	if (this->_numberOfOperand < 2)
		throw std::runtime_error("Wrong Expression: One operator is always linked by two expression ('1 2 +' or '1 2 + 2 +' are valid, '1 2 + +' is not)");
	this->_numberOfOperand--;
	return false;
}

void RPN::performOperation( char c )
{
	if (this->_execStack.size() < 2)
		throw std::runtime_error("Wrong Expression: One operator is always linked by two expression ('1 2 +' or '1 2 + 2 +' are valid, '1 2 + +' is not)");
	int topElem = this->_execStack.top();
	this->_execStack.pop();
	int secondElem = this->_execStack.top();
	this->_execStack.pop();

	switch ( c )
	{
		case '+':
		{
			this->_execStack.push( secondElem + topElem );
			break;
		}
		case '-':
		{
			this->_execStack.push( secondElem - topElem );
			break;
		}
		case '*':
		{
			this->_execStack.push( secondElem * topElem );
			break;
		}
		case '/':
		{
			if (topElem != 0)
				this->_execStack.push( secondElem / topElem );
			else
			{
				cout << "Error, some division by 0" << endl;
				this->~RPN();
				exit(1);
			}
			break;
		}
		default:
		{
			cout << "Wrong operator: " << c << endl;
			this->~RPN();
			exit(1);
		}
	}
}

string RPN::getResult() const
{
	std::cout <<"Operand: " << this->_finalNumberOperands << std::endl;
	std::cout <<"Operator: " << this->_finalNumberOperators << std::endl;
	if (this->_finalNumberOperands > this->_finalNumberOperators + 1)
		throw std::runtime_error("Wrong Expression: One operator is always linked by two expression ('1 2 +' or '1 2 + 2 +' are valid, '1 2 + +' is not)");
	return this->_result;
}
