/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:57:53 by aurel             #+#    #+#             */
/*   Updated: 2023/04/25 17:53:25 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Point.h"
#include <iostream>

int main()
{
	Point	a(0, 0);
	Point	b(0, 3);
	Point	c(2, 0);
	{
		Point toCheck(0.25, 0.25);

		if (bsp(a, b, c, toCheck))
			std::cout << "Point in " << toCheck
					  << " is inside the triangle with "
						 "vertices " << a << ", " << b << ", " << c << endl;
		else
			std::cout << "Point in " << toCheck
					  << " is not inside the triangle with "
						 "vertices " << a << ", " << b << ", " << c << endl;
	}
	Point toCheck(5, 2);
	if (bsp(a, b, c, toCheck))
		std::cout << "Point in " << toCheck << " is inside the triangle with "
											   "vertices " << b << ", " << b << ", " << c << endl;
	else
		std::cout << "Point in " << toCheck << " is not inside the triangle with "
											   "vertices " << a << ", " << b << ", " << c << endl;
	return 0;
}