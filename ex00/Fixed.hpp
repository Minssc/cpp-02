/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:18:06 by minsunki          #+#    #+#             */
/*   Updated: 2022/03/15 13:06:43 by minsunki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <string>
# include <iostream>

class	Fixed
{
	private:
		int					_value;
		const static int	_n_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &a);
		~Fixed(void);
		Fixed	&operator=(const Fixed &a); 
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

# endif