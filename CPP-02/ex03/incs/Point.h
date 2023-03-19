/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:27:02 by aurel             #+#    #+#             */
/*   Updated: 2023/03/19 21:04:02 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_POINT_H
#define CPP_POINT_H

#include <iostream>
#include "../incs/Fixed.h"
using std::endl;
using std::cout;

class Point
{
private :
	Fixed const _x;
	Fixed const _y;
public :
	Point();
	~Point();
	Point(float const x, float const y);
	Point(const Point &other);
	Point& operator=(const Point& other);
	Fixed			getX( ) const;
	Fixed			getY( ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream& out, const Point& fixed);

#endif //CPP_POINT_H
