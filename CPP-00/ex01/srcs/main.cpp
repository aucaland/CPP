/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:24:04 by aurel             #+#    #+#             */
/*   Updated: 2023/03/15 15:08:43 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"
#include "../incs/Contact.hpp"
#include "../incs/outputs.h"
#include <iostream>
#include <cstdlib>

int main()
{
	Contact		contact;
	PhoneBook	book;

	while (true)
	{
		std::cout << ENTER_AN_INPUT << std::flush;
		std::getline(std::cin, book.input);
		if (std::cin.eof())
			std::exit(EOF);
		else if (!std::cin.good() || !book.isValidInput())
			std::cout << INV_INPUT << std::endl;
		else
			book.getFunction();
		std::cin.clear();
	}
}
