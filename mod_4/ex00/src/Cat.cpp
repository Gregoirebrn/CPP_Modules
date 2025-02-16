/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/01 13:23:58 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;
}

Cat::Cat(const Cat &origin) : Animal(origin){
	std::cout << "Copy constructor operator called" << std::endl;
	this->_type = origin._type;
}

Cat &Cat::operator=(const Cat &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origin)
		return (*this);
	this->_type = origin._type;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meow?!" << std::endl;
}

