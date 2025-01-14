/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/07 14:45:32 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
	this->_type = type;
	std::cout << "WrongAnimal second constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal default destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &origin) {
	std::cout << "Copy constructor operator called" << std::endl;
	this->_type = origin._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origin)
		return (*this);
	this->_type = origin._type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Wazaaaaaaaaaaa?!" << std::endl;
}