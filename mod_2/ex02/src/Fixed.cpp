/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/25 15:10:20 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_nbr = nbr << _nbr_bits;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_nbr = roundf(nbr * (1 << _nbr_bits));
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
	return (this->_nbr);
}

void Fixed::setRawBits(const int raw) {
	this->_nbr = raw;
}

float Fixed::toFloat() const {
	return _nbr / static_cast<float>((1 << _nbr_bits));
}


int Fixed::toInt() const {
	return this->_nbr >> _nbr_bits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &fix){
	o << static_cast<float>(fix.toFloat());
	return o;
}

bool Fixed::operator>(const Fixed &fix) const
{
	return this->_nbr > fix._nbr;
}

bool Fixed::operator<(const Fixed &fix) const
{
	return this->_nbr < fix._nbr;}

bool Fixed::operator>=(const Fixed &fix) const
{
	return this->_nbr >= fix._nbr;
}

bool Fixed::operator<=(const Fixed &fix) const
{
	return this->_nbr <= fix._nbr;
}

bool Fixed::operator==(const Fixed &fix) const
{
	return this->_nbr == fix._nbr;
}

bool Fixed::operator!=(const Fixed &fix) const
{
	return this->_nbr != fix._nbr;
}

Fixed Fixed::operator+(const Fixed &fix) const
{
	Fixed out;

	out.setRawBits(this->_nbr + fix._nbr);
	return out;
}

Fixed Fixed::operator-(const Fixed &fix) const
{
	Fixed out;

	out.setRawBits(this->_nbr - fix._nbr);
	return out;}

Fixed Fixed::operator*(const Fixed &fix) const
{
	Fixed out;

	out.setRawBits(this->_nbr * fix._nbr);
	return out;
}

Fixed Fixed::operator/(const Fixed &fix) const
{
	Fixed out;

	out.setRawBits(this->_nbr / fix._nbr);
	return out;}

Fixed &Fixed::operator++(void)
{
	Fixed tmp;

	tmp = *this;
	++*this;
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	Fixed tmp;

	tmp = *this;
	--*this;
	return tmp;
}

Fixed Fixed::operator++(int digit)
{
	this->_nbr++;
	return *this;
}

Fixed Fixed::operator--(int digit)
{
	this->_nbr--;
	return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {}) {
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {}) {
	if (a < b)
		return b;
	return a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a._nbr < b._nbr)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a._nbr < b._nbr)
		return a;
	return b;
}