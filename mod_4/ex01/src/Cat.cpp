/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/26 13:08:23 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	this->brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat default destructor called" << std::endl;
}

Cat::Cat(const Cat &origine) {
	std::cout << "Cat Copy constructor operator called" << std::endl;
	this->brain = new Brain(*origine.brain);
	this->_type = origine._type;
}

Cat &Cat::operator=(const Cat &origine)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this == &origine)
		return (*this);
	delete (brain);
	this->brain = new Brain(*origine.brain);
	this->_type = origine._type;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meow?!" << std::endl;
}

