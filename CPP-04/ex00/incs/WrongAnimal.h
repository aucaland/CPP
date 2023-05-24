/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:23:27 by aucaland          #+#    #+#             */
/*   Updated: 2023/05/24 21:56:27 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

using std::string;


class WrongAnimal
{
public:
	WrongAnimal();

	virtual ~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &);

	WrongAnimal(const WrongAnimal &);

	void makeSound() const;
	virtual string getType() const;
protected:
	string type;
};

