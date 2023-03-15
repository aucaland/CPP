//
// Created by aurel on 3/12/23.
//

#include "../incs/Contact.hpp"
#include "../incs/outputs.h"
#include <cstdlib>
#include <iomanip>

string Contact::getInput(const string& str)
{
	string		line;
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

void Contact::getContactInfo()
{
	this->_firstName = Contact::getInput(FIRST_NAME);
	this->_lastName = Contact::getInput(LAST_NAME);
	this->_nickname = Contact::getInput(NICK_NAME);
	this->_phoneNumber = Contact::getInput(PHONE_NUMBER);
	this->_darkestSecret = Contact::getInput(DARKEST_SECRET);
}

string Contact::_replaceLastCharacter(string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9).append(".");
	return str;
}

void Contact::overview(int index)
{
	std::cout << std::setw(10) << index << "|" << std::flush;
	std::cout << std::setw(10) << Contact::_replaceLastCharacter(this->_firstName) << "|" << std::flush;
	std::cout << std::setw(10) << Contact::_replaceLastCharacter(this->_lastName) << "|"<< std::flush;
	std::cout << std::setw(10) << Contact::_replaceLastCharacter(this->_nickname) << "|"<< std::endl;

}

void Contact::display(int index)
{
	std::cout << "Index: " << index << std::endl;
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}


