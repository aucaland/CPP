/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:26:41 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/27 09:59:25 by aucaland         ###   ########.fr       */
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
