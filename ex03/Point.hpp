/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:56:34 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/28 12:56:37 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
# define __POINT_HPP__

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	
	public:
		Point(void);
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &p);
		~Point(void);
		
		const Point	&operator=(const Point &p);
		// const Point	operator-(const Point &p) const;
		
		const Fixed	&getX(void) const;
		const Fixed &getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

# endif