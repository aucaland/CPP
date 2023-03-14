//
// Created by aurel on 3/12/23.
//

#ifndef CPP_00_PHONEBOOK_H
#define CPP_00_PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
private :
	Contact contacts[8];

public :
	PhoneBook();
	~PhoneBook();
	void add(void);
	void print(void);
	void search(void);
};


#endif //CPP_00_PHONEBOOK_H
