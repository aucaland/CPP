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
#include "WrongAnimal.h"
using std::string;


class WrongCat : public WrongAnimal
{
public:
	WrongCat();

	~WrongCat();

	WrongCat &operator=(const WrongCat &);

	WrongCat(const WrongCat &);
	void makeSound() const;
private:
	string type;
};
