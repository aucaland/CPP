/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:41:05 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/27 13:44:08 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

using std::string;

class AMateria
{
protected:
	string _type;

public:
	AMateria();
	~AMateria();

	AMateria(string const & type);

	AMateria &operator=(const AMateria &);
	AMateria(const AMateria &);

	string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif //CPP_AMATERIA_H
