/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:23:27 by aucaland          #+#    #+#             */
/*   Updated: 2023/05/24 22:11:30 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.h"
using std::string;


class Animal
{
public:
	Animal();

	virtual ~Animal();

	virtual Animal &operator=(const Animal &);

	Animal(const Animal &);

	virtual void makeSound() const;
	virtual string getType() const;
	virtual	Brain* getBrain() const = 0; //we could just implement this in animal class but its useless (see next exercice)
protected:
	string _type;
};

