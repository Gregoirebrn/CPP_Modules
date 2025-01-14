/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:01:37 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/01 14:13:31 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain default destructor called" << std::endl;
}

Brain::Brain(const Brain &origin) {
	std::cout << "Brain Copy constructor operator called" << std::endl;
	*this = origin;
}

Brain &Brain::operator=(const Brain &origin) {
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this == &origin)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = origin._ideas[i];
	return (*this);
}
