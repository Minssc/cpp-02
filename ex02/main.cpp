/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:17:39 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/25 11:54:53 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	std::cout.precision(16);
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed(0.42f) << std::endl;

	std::cout << Fixed(42) - Fixed(0.42f) << std::endl;
	std::cout << Fixed(42) + Fixed(0.42f) << std::endl;
	std::cout << Fixed(42) / Fixed(0.42f) << std::endl;
	std::cout << (Fixed(42) < Fixed(42.42f)) << std::endl;
	std::cout << (Fixed(42) > Fixed(42.42f)) << std::endl;
	std::cout << (Fixed(42) == Fixed(42)) << std::endl;
	return 0;
}