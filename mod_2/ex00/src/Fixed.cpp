/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/23 18:56:23 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fix) {
	std::cout << "Copy constructor operator called" << std::endl;
	this->_nbr = fix.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fix) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fix)
		return (*this);
	this->_nbr = fix.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nbr);
}

void Fixed::setRawBits(const int raw) {
	std::cout << "Setter of Fixed Called" << std::endl;
	this->_nbr = raw;
}
