/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:26:29 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/26 14:03:50 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.h"
#include "Brain.h"
using std::string;


class Cat : public Animal
{
public:
	Cat();

	~Cat();

	Cat &operator=(const Cat &);
	Animal &operator=(const Animal & other);

	Cat(const Cat &);
	virtual void makeSound() const;
	Brain* getBrain() const;
private:
	Brain* _brain;
};
