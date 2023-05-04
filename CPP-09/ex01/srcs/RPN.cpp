//
// Created by aucaland on 5/2/23.
//

#include "../incs/RPN.h"

using std::cout;
using std::endl;

const string RPN::validArgs = "*/+-0123456789";

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
	if (this != &other)
		this->_result = other._result;
	cout << "Constructor assignement RPN called" << endl;
	return *this;
}

bool RPN::ValidArg( char c ) {
	if ( validArgs.find( c ) != string::npos )
		return true;
	return false;
}

bool RPN::tooMuchConsecutivOperand() {
	if (++this->_consecutivOperandCount >= 3)
		return true;
	return false;
}

bool RPN::rpnIsValid( char c )
{
	if (!ValidArg( c ))
		return false;
	return true;
}

RPN::RPN( char *rpnExpression ) : _consecutivOperandCount(0), _numberOfOperand(0), _result(NULL)
{
	rpn(rpnExpression);
}

void RPN::rpn( char *rpnExpression )
{
	string rpnStringExpression(rpnExpression);
	string::iterator it;
	for (it = rpnStringExpression.begin(); it != rpnStringExpression.end(); it++)
	{
		while( it != rpnStringExpression.end() && *it == ' ' )
			it++;
		if (it == rpnStringExpression.end() && checkEnd())
			return ;
		if ( rpnIsValid( *it ) && isOperand( *it ) && !tooMuchConsecutivOperand())
		{
			this->_numberOfOperand++;
			_execStack.push( *it - 48 );
		}
		else if ( rpnIsValid( *it ) && isOperator( *it ) && !tooMuchOperators())
			performOperation( *it );
	}
}

bool RPN::isOperand( char c )
{
	if (operands.find(c))
	{
		this->_numberOfOperand++;
		return true;
	}
	return false;
}

bool RPN::isOperator( char c )
{
	return (operators.find(c));
}

bool RPN::checkEnd()
{
	if(this->_result == NULL)
	{
		cout << "Wrong expression" << endl;
		return false;
	}
	return true;
}

bool RPN::tooMuchOperators()
{
	if (_numberOfOperand < 2)
		return true;
	_numberOfOperand--;
	return false;
}

void RPN::performOperation( char c )
{
	if (this->_execStack.size() < 2)
	{
		cout << "Wrong Expression: One operator is always linked by two expression ('1 2 +' or '1 2 + 2 + are valid, '1 2 + +' is not)"
	}
	int topElem = this->_execStack.top();
	this->_execStack.pop();
	int secondElem = this->_execStack.top();
	this->_execStack.pop();

	switch ( c )
	{
		case '+':
		{
			this->_execStack.push( secondElem + topElem );
		}
		case '-':
		{
			this->_execStack.push( secondElem - topElem );
		}
		case '*':
		{
			this->_execStack.push( secondElem * topElem );
		}
		case '/':
		{
			if (topElem != 0)
				this->_execStack.push( secondElem / topElem );
			else
			{
				cout << "Error, some division by 0" << endl;
				exit(1);
			}
		}
		default:
		{
			cout << "Wrong operator: " << c << endl;
			exit(1);
		}
	}
}