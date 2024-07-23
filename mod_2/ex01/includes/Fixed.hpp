/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:30:46 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/23 19:15:05 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
private:
	int 				_nbr;
	const static int	_nbr_bits = 8;
public:
	const int	cint = 8;
	const float	cflo = 8;
	Fixed();
	~Fixed();
	Fixed (const Fixed &);
	Fixed &operator=(const Fixed &fix);
	float &operator<<(const int fix);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

#endif
