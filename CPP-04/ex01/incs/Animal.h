/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:23:27 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/26 13:09:45 by aurel            ###   ########.fr       */
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
	virtual	Brain* getBrain() const = 0;
protected:
	string _type;
};

