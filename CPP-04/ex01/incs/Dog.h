/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:26:41 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/26 14:03:50 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.h"
#include "Brain.h"
using std::string;


class Dog : public Animal
{
public:
	Dog();

	~Dog();

	Dog &operator=(const Dog &);
	Animal &operator=( const Animal & other );

	Dog(const Dog &);
	virtual void makeSound() const;
	Brain* getBrain() const;
private :
	Brain* _brain;
};
