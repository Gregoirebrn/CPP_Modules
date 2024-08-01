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

Dog::Dog(const Dog &origine) {
	std::cout << "Copy constructor operator called" << std::endl;
	this->_type = origine._type;
}

Dog &Dog::operator=(const Dog &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origine)
		return (*this);
	this->_type = origine._type;
	return (*this);
}
