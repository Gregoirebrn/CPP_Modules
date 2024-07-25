/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:30:46 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/25 17:30:18 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Point{
private:
	const int _x;
	const int _y;
public:
	Point;
	~Point();
};

class Fixed{
private:
	int 				_nbr;
	const static int	_nbr_bits = 8;
public:
	Fixed();
	Fixed(const int nbr);
	Fixed(const float nbr);
	~Fixed();
	Fixed (const Fixed &);
	Fixed &operator=(const Fixed &fix);

	bool operator>(const Fixed &fix) const;
	bool operator<(const Fixed &fix) const;
	bool operator>=(const Fixed &fix) const;
	bool operator<=(const Fixed &fix) const;
	bool operator==(const Fixed &fix) const;
	bool operator!=(const Fixed &fix) const;

	Fixed operator+(const Fixed &fix) const;
	Fixed operator-(const Fixed &fix) const;
	Fixed operator*(const Fixed &fix) const;
	Fixed operator/(const Fixed &fix) const;

	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &, Fixed const &fix);

#endif
