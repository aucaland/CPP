/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:04:10 by aurel             #+#    #+#             */
/*   Updated: 2023/03/26 14:02:32 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

using std::string;


class Brain
{
public:
	Brain();

	~Brain();

	Brain &operator=( const Brain & );

	Brain( const Brain & );
	string _ideas[100];
};
