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

Base::Base() {
	std::cout << "Base default constructor called" << std::endl;
}

Base::~Base() {
	std::cout << "Base default destructor called" << std::endl;
}

Base::Base(const Base &origin) {
	std::cout << "Copy constructor operator called" << std::endl;
	(void)origin;
}

Base &Base::operator=(const Base &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->exemple = origin.exemple;
	return (*this);
}

uintptr_t Base::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Base::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
