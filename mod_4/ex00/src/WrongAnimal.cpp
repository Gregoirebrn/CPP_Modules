/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/01 13:34:11 by grebrune         ###   ########.fr       */
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

WrongAnimal::WrongAnimal(const WrongAnimal &origine) {
	std::cout << "Copy constructor operator called" << std::endl;
	this->_type = origine._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origine)
		return (*this);
	this->_type = origine._type;
	return (*this);
}

std::string const WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const {
	if (this->getType() == "Cat")
		std::cout << "Meow?!" << std::endl;
	else if (this->getType() == "Dog")
		std::cout << "Waaff?!" << std::endl;
	else
		std::cout << "Wazaaaaaaaaaaa?!" << std::endl;
	return ;
}