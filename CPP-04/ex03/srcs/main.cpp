/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:38:12 by aucaland          #+#    #+#             */
/*   Updated: 2023/05/24 22:42:44 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../incs/Ice.h"
#include "../incs/Cure.h"
#include "../incs/Character.h"
#include "../incs/MateriaSource.h"

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");

	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	me->unequip(1);
	me->unequip(0);
	delete bob;
	delete me;
	delete src;
	return 0;
}
