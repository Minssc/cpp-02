/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:18:21 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/25 16:09:28 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _raw(0) 
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int a)
{
	// std::cout << "Int constructor called" << std::endl;
	_raw = a << _n_bits;
}

Fixed::Fixed(float a)
{
	// std::cout << "Float constructor called" << std::endl;
	_raw = roundf(a * (1 << _n_bits));
}

Fixed::Fixed(const Fixed &a)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

Fixed::~Fixed(void) 
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &a)
{
	// std::cout << "Assignment operator called" << std::endl;
	this->_raw = a.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &a) const
{
	Fixed	ret;
	ret.setRawBits(this->_raw + a.getRawBits());
	// this->_raw = roundf((this->_raw + a.getRawBits()) / (1 << _n_bits));
	// this->_raw = roundf((this->toFloat() + a.toFloat()) * (1 << _n_bits));
	return (ret);
}

Fixed	Fixed::operator-(const Fixed &a) const
{
	Fixed	ret;
	ret.setRawBits(this->_raw - a.getRawBits());
	return (ret);
	// this->_raw -= a.getRawBits();
	// return (*this);
}

Fixed	Fixed::operator*(const Fixed &a) const
{
	Fixed	ret;
	ret.setRawBits((this->_raw * a.getRawBits()) >> _n_bits);
	return (ret);
	// this->_raw *= a.getRawBits();
	// return (*this);
}

Fixed	Fixed::operator/(const Fixed &a) const
{
	Fixed	ret;
	ret.setRawBits((static_cast<float>(this->_raw) / a.getRawBits()) * (1 << _n_bits));
	return (ret);
	// this->_raw /= a.getRawBits();
	// return (*this);
}

// Fixed	&Fixed::operator+=(const Fixed &a)
// {
// 	this->_raw += a.getRawBits();
// 	return (*this);
// }

// Fixed	&Fixed::operator-=(const Fixed &a)
// {
// 	this->_raw -= a.getRawBits();
// 	return (*this);
// }

// Fixed	&Fixed::operator*=(const Fixed &a)
// {
// 	this->_raw *= a.getRawBits();
// 	return (*this);
// }

// Fixed	&Fixed::operator/=(const Fixed &a)
// {
// 	this->_raw /= a.getRawBits();
// 	return (*this);
// }

Fixed	&Fixed::operator++(void)
{
	this->_raw++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;
	this->operator++();
	return (old);
}

Fixed	&Fixed::operator--(void)
{
	this->_raw--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old = *this;
	this->operator--();
	return (old);
}

bool	Fixed::operator!(void) const
{
	return (!this->_raw);
}

bool	Fixed::operator<(const Fixed &a) const
{
	return (this->getRawBits() < a.getRawBits());
}

bool	Fixed::operator<=(const Fixed &a) const
{
	return (this->getRawBits() <= a.getRawBits());
}

bool	Fixed::operator>(const Fixed &a) const
{
	return (this->getRawBits() > a.getRawBits());
}

bool	Fixed::operator>=(const Fixed &a) const
{
	return (this->getRawBits() >= a.getRawBits());
}

bool	Fixed::operator==(const Fixed &a) const
{
	return (this->getRawBits() == a.getRawBits());
}

bool	Fixed::operator!=(const Fixed &a) const
{
	return (this->getRawBits() != a.getRawBits());
}

int		Fixed::getRawBits(void) const
{
	return (_raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

void	Fixed::printRawBits(void) const
{
	for(int i = 0; i < 32; ++i)
	{
		std::cout << ((this->getRawBits() & (1 << (32 - i))) ? 1 : 0);
		if (i != 0 && (i % 8) == 0)
			std::cout << " ";
	}
	std::cout << std::endl;
}

float	Fixed::toFloat(void) const
{
	// float	ret;

	// ret = (this->getRawBits() >> _n_bits);
	// for(int i = 1; i <= 8; ++i)
	// 	if ((this->getRawBits() >> (8 - i)) & 1)
	// 		ret += (1.0f / (1 << i));
	// return (ret);
	return (static_cast<float>(_raw) / (1 << _n_bits));
}

int		Fixed::toInt(void) const
{
	return (_raw >> _n_bits);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

std::ostream	&operator<<(std::ostream &o, const Fixed &f)
{
	return (o << f.toFloat());
}

// Fixed	&operator+(Fixed &a, const Fixed &b)
// {
// 	a += b;
// 	return (a);
// }

// Fixed	&operator+(Fixed a, Fixed b)
// {
// 	a += b;
// 	return (a);
// }

// Fixed	&operator-(Fixed &a, const Fixed &b)
// {
// 	a -= b;
// 	return (a);
// }

// Fixed	&operator-(Fixed a, Fixed b)
// {
// 	a -= b;
// 	return (a);
// }

// Fixed	&operator*(Fixed &a, const Fixed &b)
// {
// 	a *= b;
// 	return (a);
// }

// bool	&operator<(const Fixed &a, const Fixed &b)
// {
// 	return (a < b);
// }

// bool	&operator>(const Fixed &a, const Fixed &b)
// {
// 	return (a > b);
// }