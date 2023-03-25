/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:26:29 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/25 12:22:07 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.h"
using std::string;


class Cat : public Animal
{
public:
	Cat();

	~Cat();

	Cat &operator=(const Cat &);

	Cat(const Cat &);
	virtual void makeSound() const;
private:
	string type;
};
