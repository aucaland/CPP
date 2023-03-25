/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:26:41 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/25 12:22:07 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.h"
using std::string;


class Dog : public Animal
{
public:
	Dog();

	~Dog();

	Dog &operator=(const Dog &);

	Dog(const Dog &);
	virtual void makeSound() const;
private :
	string type;
};
