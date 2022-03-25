/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:17:39 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/25 16:07:34 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

static void checkpoint(Point a, Point b, Point c, Point p)
{
	if (bsp(a,b,c,p))
		std::cout<< "IN!" << std::endl;
	else
		std::cout<< "OUT!" << std::endl;
}

int main( void ) 
{
	// Point a;
	// Point b(Fixed(1),Fixed(1));

	// a = a;
	// std::cout << a.getX() << "," << a.getY() << std::endl;

	Point a(Fixed(0),Fixed(0));
	Point b(Fixed(10),Fixed(0));
	Point c(Fixed(0),Fixed(10));

	checkpoint(a,b,c,Point(Fixed(0),Fixed(0)));
	checkpoint(a,b,c,Point(Fixed(5),Fixed(0)));
	checkpoint(a,b,c,Point(Fixed(0.01f),Fixed(0.01f)));
	checkpoint(a,b,c,Point(Fixed(10.0f),Fixed(0)));
	
	return 0;
}