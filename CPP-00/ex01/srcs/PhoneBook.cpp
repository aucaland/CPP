//
// Created by aurel on 3/12/23.
//

#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "../incs/PhoneBook.hpp"
#include "../incs/outputs.h"

PhoneBook::PhoneBook()
{
	this->_isFull = false;
	this->_lastAdd = 0;
	this->input = "";
	this->_bookSize = 0;
}

void PhoneBook::add()
{
	PhoneBook::_increaseLastAdd();
	PhoneBook::_contacts[_lastAdd - 1].getContactInfo();
}

int PhoneBook::_increaseLastAdd()
{
	if (_lastAdd == 8)
	{
		_isFull = true;
		_lastAdd = 1;
	}
	else
		_lastAdd++;
	if (_bookSize != 8)
		_bookSize++;
	return _lastAdd;
}

bool PhoneBook::isValidInput() const
{
	if (input == "SEARCH" || input == "EXIT" || input == "ADD")
		return true;
	return false;
}

void PhoneBook::getFunction()
{
	if (input == "SEARCH")
		search();
	else if (input == "ADD")
		add();
	else if (input == "EXIT")
		exitPhoneBook();
}

void PhoneBook::search()
{
	string 		line;
	int 		index;

	this->printContactList();
	std::cout << ENTER_INDEX_CONTACT << std::flush;
	std::getline(std::cin, line);
	std::stringstream ss(line);
	ss >> index;
	if (index > _bookSize || index < 1)
		std::cout << INV_INDEX << std::endl;
	else
		_contacts[index - 1].display(index);
	std::cin.clear();
}

void PhoneBook::printContactList()
{
	std::cout << std::setw(10) << "Index" << "|" << std::flush;
	std::cout << std::setw(10) << "First name" << "|" << std::flush;
	std::cout << std::setw(10) << "Last name" << "|" << std::flush;
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->_bookSize; i++)
		_contacts[i].overview(i);
}

void PhoneBook::exitPhoneBook()
{
	std::cin.clear();
	std::exit(0);
}

