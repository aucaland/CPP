/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:26:29 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/24 15:26:29 by aucaland         ###   ########.fr       */
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
};


#endif //CPP_CAT_H
