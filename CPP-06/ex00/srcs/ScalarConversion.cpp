//
// Created by aurel on 4/12/23.
//

#include "../incs/ScalarConversion.h"


void ScalarConversion::convert( string litteral )
{
	switch ( findEntryType( litteral ) )
	{
		case DOUBLE:
		{
			convertDouble( litteral );
			break;
		}
		case INT:
		{
			convertInt( litteral );
			break;
		}
		case CHAR:
		{
			convertChar( litteral );
			break;
		}
		case FLOAT:
		{
			convertFloat( litteral );
			break;
		}
		default:
			cout << "Unknown Entry type" << endl;
	}

}

int ScalarConversion::findEntryType(string litteral)
{
	if (checkInt(litteral))
		return INT;
	else if(checkChar(litteral))
		return CHAR;
	else if (checkDouble(litteral))
		return DOUBLE;
	else if (checkFloat(litteral))
		return FLOAT;
	else
		return ERROR;
}

void ScalarConversion::convertInt(string litteral)
{

	(void)litteral;
	cout << "ConvertToInt" << endl;
}

void ScalarConversion::convertFloat(string litteral)
{
	float realTypeLitteral;
	std::istringstream iss(litteral);
	iss >> realTypeLitteral;

	if ( std::isprint(static_cast<char>(realTypeLitteral)))
		cout << "char: " << static_cast<char>(realTypeLitteral) << endl;
	else
		cout << "char: impossible" << endl;
	if ( std::abs(realTypeLitteral) < std::numeric_limits<int>::max())
		cout << "int: " << static_cast<int>(realTypeLitteral) << endl;
	else
		cout << "int: impossible" << endl;
	cout << "double: " << static_cast<double>(realTypeLitteral) << endl;
}

void ScalarConversion::convertDouble(string litteral)
{
	(void)litteral;
	cout << "ConvertToDouble" << endl;

}

void ScalarConversion::convertChar(string litteral)
{
	(void)litteral;
	cout << "ConvertToChar" << endl;
}

bool ScalarConversion::checkInt(string litteral)
{
	int myInt;

	std::stringstream ss(litteral);
	ss >> myInt;

	if ( !ss.fail() && ss.eof())
	{
		return true;
	}
	return false;
}

bool ScalarConversion::checkFloat(string litteral)
{
	size_t i = 0;
	bool signLitteral = false;
	if (litteral[0] == '-' || litteral[0] == '+') {
		i++;
		signLitteral = true;
	}
	bool decimal = false;
	for (; i < litteral.size(); i++) {
		if (litteral[i] == '.' && ((i > 0 && !signLitteral) || (i > 1))) {
			decimal = true;
			break;
		}
		if (!isdigit(litteral[i])) {
			return false;
		}
	}
	if (litteral[litteral.size() - 1] == 'f') {
			return decimal;
	}
	return false;
}

bool ScalarConversion::checkDouble(string litteral)
{
	double myDouble;

	std::stringstream ss(litteral);
	ss >> myDouble;

	if ( !ss.fail() && ss.eof() )
		return true;
	return false;
}

bool ScalarConversion::checkChar(string litteral)
{
	char myChar;

	if (litteral.size() == 1 && std::isprint(litteral[0]))
	{
		std::stringstream ss(litteral);
		ss >> myChar;

		if ( !ss.fail() )
			return true;
	}
	return false;
}




