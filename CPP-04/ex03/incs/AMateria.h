/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:41:05 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/30 13:57:27 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.h"

using std::string;

class AMateria
{
protected:
	string _type;

public:
	AMateria();
	virtual ~AMateria();

	AMateria(string const & type);

	AMateria &operator=(const AMateria &);
	AMateria(const AMateria &);

	string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif //CPP_AMATERIA_H
