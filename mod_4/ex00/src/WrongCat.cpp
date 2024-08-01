/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/01 13:38:26 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : _type("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &origine) {
	std::cout << "Copy constructor operator called" << std::endl;
	this->_type = origine._type;
}

WrongCat &WrongCat::operator=(const WrongCat &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origine)
		return (*this);
	this->_type = origine._type;
	return (*this);
}
