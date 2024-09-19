/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:49:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/18 14:26:59 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Base::Base() {
	std::cout << "Base default constructor called" << std::endl;
}

Base::~Base() {
	std::cout << "Base default destructor called" << std::endl;
}

Base::Base(const Base &origine) {
	std::cout << "Copy constructor operator called" << std::endl;
	(void)origine;
}

Base &Base::operator=(const Base &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void)origine;
	return (*this);
}

uintptr_t Base::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Base::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
