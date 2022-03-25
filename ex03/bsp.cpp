/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:56:55 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/25 16:08:47 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

// float sign (fPoint p1, fPoint p2, fPoint p3)
// {
//     return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
// }

// bool PointInTriangle (fPoint pt, fPoint v1, fPoint v2, fPoint v3)
// {
//     float d1, d2, d3;
//     bool has_neg, has_pos;

//     d1 = sign(pt, v1, v2);
//     d2 = sign(pt, v2, v3);
//     d3 = sign(pt, v3, v1);

//     has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
//     has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

//     return !(has_neg && has_pos);
// }

static Fixed sign(const Point &a, const Point &b, const Point &c)
{
	return (a.getX() - c.getX()) * (b.getY() - c.getY()) -
		(b.getX() - c.getX()) * (a.getY() - c.getY());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1, d2,d3;
	bool	has_neg, has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	std::cout << d1 << ", " << d2 << ", " << d3 << std::endl;
	if (!d1 || !d2 || !d3)
		return (false);
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return (!(has_neg && has_pos));
}