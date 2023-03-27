/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:26:29 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/27 09:59:25 by aucaland         ###   ########.fr       */
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
