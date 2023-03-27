/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:09:16 by aurel             #+#    #+#             */
/*   Updated: 2023/03/27 13:36:29 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Animal.h"
#include "../incs/WrongAnimal.h"
#include "../incs/WrongCat.h"
#include "../incs/Dog.h"
#include "../incs/Cat.h"
#include "../incs/Brain.h"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	////////////////////
//	Animal notInstantiable;
	////////////////////
	delete j;//should not create a leak
	delete i;
	std::cout << "1----------------------" << std::endl;
	Dog basic;
	Cat basic1;
	{
		Dog tmp = basic;
		Cat tmp1 = basic1;
	}
	std::cout << "2--------------------------" << std::endl;

	const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
	Brain* brain = animals[1]->getBrain();
	Brain* brain2 = animals[2]->getBrain();
	std::cout << "3--------------------------" << std::endl;

	brain->_ideas[0] = "I think so I am";
	brain2->_ideas[50] = "Where are my kibbles, human !";
	std::cout << "4--------------------------" << std::endl;

	animals[1]->makeSound();
	std::cout << brain->_ideas[0] << std::endl;
	std::cout << brain->_ideas[1] << std::endl;
	animals[2]->makeSound();
	std::cout << brain2->_ideas[50] << std::endl;
	std::cout << brain2->_ideas[1] << std::endl;
	std::cout << "5--------------------------" << std::endl;

	for ( int i = 0; i < 4; i++ ) {
		delete animals[i];
	}
	std::cout << "6--------------------------" << std::endl;
	return 0;
}