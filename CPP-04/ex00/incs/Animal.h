/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:23:27 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/25 12:22:25 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

using std::string;


class Animal
{
public:
	Animal();

	virtual ~Animal();

	Animal &operator=(const Animal &);

	Animal(const Animal &);

	virtual void makeSound() const;
	virtual string getType() const;
protected:
	string type;
};

