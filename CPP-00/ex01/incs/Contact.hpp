//
// Created by aurel on 3/12/23.
//

#ifndef CPP_00_CONTACT_HPP
#define CPP_00_CONTACT_HPP

#include <iostream>
//#include "PhoneBook.hpp"
using std::string;

class Contact
{
private :
	string	_firstName;
	string	_lastName;
	string	_nickname;
	string	_phoneNumber;
	string	_darkestSecret;

	static string			getInput(const string& str);
	static string			_replaceLastCharacter(string str);

public :
	void		getContactInfo();
	void		display(int);
	void		overview(int);
};


#endif //CPP_00_CONTACT_HP
