/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:30:46 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/23 18:51:40 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
private:
	int 				_nbr;
	static const int	_nbr_bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed (const Fixed &);
	Fixed &operator=(const Fixed &fix);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
