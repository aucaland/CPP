//
// Created by aurel on 3/12/23.
//

#include "../incs/Contact.hpp"
#include "../incs/outputs.h"
#include <cstdlib>

string Contact::getInput(string str)
{
	string	line;
	bool		is_valid = false;
	while (!is_valid)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, line);
		if (std::cin.eof())
			std::exit(EOF);
		if (std::cin.good() && !line.empty())
			is_valid = true;
		else
		{
			std::cin.clear();
			std::cout << INV_INPUT << std::endl;
		}
	}
	return (line);
}

void Contact::askInput(void)
{
	this->_firstName = Contact::getInput(FIRST_NAME);
	this->_lastName = Contact::getInput(LAST_NAME);
	this->_nickname = Contact::getInput(NICK_NAME);
	this->_phoneNumber = Contact::getInput(PHONE_NUMBER);
	this->_darkestSecret = Contact::getInput(DARKEST_SECRET);
}