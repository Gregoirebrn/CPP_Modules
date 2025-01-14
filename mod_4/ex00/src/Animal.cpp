/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/31 15:30:17 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("default") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) {
	this->_type = type;
	std::cout << "Animal second constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal default destructor called" << std::endl;
}

Animal::Animal(const Animal &origin) {
	std::cout << "Copy constructor operator called" << std::endl;
	this->_type = origin._type;
}

Animal &Animal::operator=(const Animal &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origin)
		return (*this);
	this->_type = origin._type;
	return (*this);
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::makeSound() const {
	std::cout << "Wazaaaaaaaaaaa?!" << std::endl;
}