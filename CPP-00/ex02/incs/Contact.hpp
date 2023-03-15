//
// Created by aurel on 3/12/23.
//

#ifndef CPP_00_CONTACT_HPP
#define CPP_00_CONTACT_HPP

#include <iostream>
using std::string;

class Contact
{
private :
	string	_firstName;
	string	_lastName;
	string	_nickname;
	string	_phoneNumber;
	string	_darkestSecret;

public :
	void		askInput(void);
	void		display(void);
	string	getInput(string str);
};


#endif //CPP_00_CONTACT_HP
