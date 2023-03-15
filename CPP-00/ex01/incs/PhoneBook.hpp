//
// Created by aurel on 3/12/23.
//

#ifndef CPP_00_PHONEBOOK_H
#define CPP_00_PHONEBOOK_H

#include "Contact.hpp"
using std::string;

class PhoneBook
{
private :
	Contact	_contacts[8];
	int 	_lastAdd;
	bool	_isFull;
	int 	_bookSize;

	int 	_increaseLastAdd();

public :
	PhoneBook();
	string 	input;
	void	getFunction();
	bool	isValidInput() const;
	void	add();
	void	printContactList();
	void	search();
	static void	exitPhoneBook();
};


#endif //CPP_00_PHONEBOOK_H
