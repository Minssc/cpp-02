/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:56:28 by minsunki          #+#    #+#             */
/*   Updated: 2022/04/03 17:02:22 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {}

Point::Point(const Fixed &x, const Fixed &y): _x(x), _y(y) {}

Point::Point(const Point &p): _x(p.getX()), _y(p.getY()) {}

Point::~Point(void) {}

const Point	&Point::operator=(const Point &p)
{
	// *this = Point(p);
	// const_cast<Fixed&>(_x) = p.getX();
	// const_cast<Fixed&>(_y) = p.getY();
	static_cast<void>(p);
	return (*this);
}

const Fixed	&Point::getX(void) const
{
	return (_x);
}

const Fixed	&Point::getY(void) const
{
	return (_y);
}