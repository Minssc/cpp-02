/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:18:06 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/28 12:46:57 by minsunki         ###   ########seoul.kr  */
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
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &f);

# endif