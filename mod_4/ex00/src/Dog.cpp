/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/31 14:50:38 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;
}

Dog::Dog(const Dog &origin) : Animal(origin) {
	std::cout << "Copy constructor operator called" << std::endl;
	this->_type = origin._type;
}

Dog &Dog::operator=(const Dog &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origin)
		return (*this);
	this->_type = origin._type;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Waaff?!" << std::endl;
}