/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:02:13 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/15 16:04:49 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name) {}

HumanB::~HumanB() {
	std::cout << "Destructor of HumanB Called" << std::endl;
}

void HumanB::attack() const{
	std::cout << this->_name << "attacks with their" << this->_weapon << std::endl;
}

void HumanB::setWeapon(Weapon& new_weapon) {
	this->_weapon = &new_weapon;
}