/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:00:45 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/15 16:01:20 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon), _name(name) {}

HumanA::~HumanA() {
	std::cout << "Destructor of HumanA Called" << std::endl;
}

void HumanA::attack(){
	std::cout << this->_name << "attacks with their " << _weapon.getType() << std::endl;
}