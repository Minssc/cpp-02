/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:18:06 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/28 12:53:17 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <string>
# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_raw;
		const static int	_n_bits = 8;

	public:
		Fixed(void);
		Fixed(const int a);
		Fixed(const float a);
		Fixed(const Fixed &a);
		~Fixed(void);

		Fixed			&operator=(const Fixed &a); 
		Fixed			operator+(const Fixed &a) const;
		Fixed			operator-(const Fixed &a) const;
		Fixed			operator*(const Fixed &a) const;
		Fixed			operator/(const Fixed &a) const;
		// Fixed			&operator+=(const Fixed &a);
		// Fixed			&operator-=(const Fixed &a);
		// Fixed			&operator*=(const Fixed &a);
		// Fixed			&operator/=(const Fixed &a);
		Fixed			&operator++(void);
		Fixed			operator++(int);
		Fixed			&operator--(void);
		Fixed			operator--(int);

		bool			operator!(void) const;
		bool			operator<(const Fixed &a) const;
		bool			operator<=(const Fixed &a) const;
		bool			operator>(const Fixed &a) const;
		bool			operator>=(const Fixed &a) const;
		bool			operator!=(const Fixed &a) const;
		bool			operator==(const Fixed &a) const;
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		void			printRawBits(void) const;
		float			toFloat(void) const;
		int				toInt(void) const;

		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

};

std::ostream	&operator<<(std::ostream &o, const Fixed &f);
// Fixed			&operator+(Fixed &a, const Fixed &b);
// Fixed			&operator+(Fixed a, Fixed b);
// Fixed			&operator-(Fixed &a, const Fixed &b);
// Fixed			&operator-(Fixed a, Fixed b);
// Fixed			&operator*(Fixed &a, const Fixed &b);
// Fixed			&operator*(Fixed a, Fixed b);
// Fixed			&operator/(Fixed &a, const Fixed &b);
// Fixed			&operator/(Fixed a, Fixed b);
// bool			&operator<(const Fixed &a, const Fixed &b);
// bool			&operator>(const Fixed &a, const Fixed &b);

# endif