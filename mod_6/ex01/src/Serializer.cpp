/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:49:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/18 14:20:40 by grebrune         ###   ########.fr       */
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

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
