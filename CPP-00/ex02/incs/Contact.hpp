//
// Created by aurel on 3/12/23.
//

#ifndef CPP_00_CONTACT_HPP
#define CPP_00_CONTACT_HPP

#include <iostream>

class Contact
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;

	public :
		Contact();
		~Contact();
		void display(void);
};


#endif //CPP_00_CONTACT_HP
