/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:49:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/17 18:49:12 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::~Serializer() {
	std::cout << "Serializer default destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &origine) {
	std::cout << "Copy constructor operator called" << std::endl;
	(void)origine;
}

Serializer &Serializer::operator=(const Serializer &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void)origine;
	return (*this);
}

