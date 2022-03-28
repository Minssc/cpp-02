/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:18:21 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/28 12:47:09 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _raw(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int a)
{
	std::cout << "Int constructor called" << std::endl;
	_raw = a << _n_bits;
}

Fixed::Fixed(const float a)
{
	std::cout << "Float constructor called" << std::endl;
	_raw = roundf(a * (1 << _n_bits));
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

Fixed::~Fixed(void) 
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = a.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_raw) / (1 << _n_bits));
}

int		Fixed::toInt(void) const
{
	return (_raw >> _n_bits);
}

std::ostream	&operator<<(std::ostream &o, const Fixed &f)
{
	return (o << f.toFloat());
}