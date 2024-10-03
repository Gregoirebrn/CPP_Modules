/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:51:16 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 17:53:31 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::~Serializer() {
	std::cout << "Serializer default destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &origin) {
	std::cout << "Copy constructor operator called" << std::endl;
	(void)origin;
}

Serializer &Serializer::operator=(const Serializer &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->exemple = origin.exemple;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
