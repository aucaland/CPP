/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:27:17 by aurel             #+#    #+#             */
/*   Updated: 2023/04/25 17:48:27 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Point.h"
#include <cmath>

Fixed	getTriangleArea( Point const a, Point const b, Point const c )
{
	Fixed	area((Fixed(1) / Fixed(2)) * ((a.getX()) * (b.getY() - c.getY()) + b.getX() * (c
	.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())));

	if (area < 0)
		return area * -1;
	return area;
}

Fixed	lineEquation( Fixed pente, Fixed b, Point point)
{
	return (pente * point.getX() + b - point.getY());
}

bool pointOnEdge( Point const a, Point const b, Point const c, Point const
point )
{
	Fixed penteA((b.getY() - a.getY()) / (b.getX() - a.getX()));
	Fixed penteB((c.getY() - b.getY()) / (c.getX() - b.getX()));
	Fixed penteC((a.getY() - c.getY()) / (a.getX() - c.getX()));
	Fixed bA(a.getY() - penteA * a.getX());
	Fixed bB(a.getY() - penteB * a.getX());
	Fixed bC(a.getY() - penteC * a.getX());

	if (lineEquation( penteA, bA, point) == Fixed(0)
			|| lineEquation( penteB, bB,point) == Fixed(0)
			|| lineEquation(penteC,bC, point) == Fixed(0))
		return true;
	return false;

}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	triangleArea(getTriangleArea(a, b, c));
	Fixed	areaA(getTriangleArea(a, b, point));
	Fixed	areaB(getTriangleArea(b, c, point));
	Fixed	areaC(getTriangleArea(c, a, point));


	std::cout << "triangleTot = " << triangleArea.toFloat() << ", aireA = " << areaA.toFloat() << endl;
	if ((areaA + areaB + areaC) == triangleArea && !(pointOnEdge(a, b, c,
																 point)))
		return true;
	return false;
}