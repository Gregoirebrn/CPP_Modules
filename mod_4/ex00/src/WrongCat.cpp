/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/07 14:43:09 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &origin) : WrongAnimal(origin) {
	std::cout << "Copy constructor operator called" << std::endl;
	this->_type = origin._type;
}

WrongCat &WrongCat::operator=(const WrongCat &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origin)
		return (*this);
	this->_type = origin._type;
	return (*this);
}
