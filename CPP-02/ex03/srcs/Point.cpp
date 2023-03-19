//
// Created by aurel on 3/19/23.
//

#include "../incs/Point.h"

Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{

}

Point::~Point()
{

}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{

}

Point::Point(const Point &other) : _x(Fixed(other._x)), _y(Fixed(other._y))
{
//	cout << "Copy constructor called" << endl;
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		( Fixed )this->_x = other._x;
		( Fixed )this->_y = other._y;
	}
	return *this;
}

Fixed Point::getY() const
{
	return this->_y;
}

Fixed Point::getX() const
{
	return this->_x;
}

std::ostream& operator<<(std::ostream& out, const Point& fixed)
{
	out << "[" << fixed.getX().toFloat();
	out << ", ";
	out << fixed.getY().toFloat() << "]";
	return out;
}