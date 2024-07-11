/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:06:59 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/10 13:48:42 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::~Zombie(void){
	std::cout << "Destructor Called" << std::endl;
}

Zombie::Zombie(void){
	std::cout << "Constructor Called" << std::endl;
}

void Zombie::annonce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	std::cout << "Constructor Called" << std::endl;
	this->_name = name;
}

std::string Zombie::getName() const {
	return this->_name;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}
