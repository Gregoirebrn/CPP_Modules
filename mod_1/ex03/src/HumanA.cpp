/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:00:45 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/13 12:24:42 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon){
	this->_name = name;
	this->_weapon = weapon.getType();
	std::cout << "Constructor of HumanA Called" << std::endl;
}

HumanA::~HumanA() {
	std::cout << "Destructor of HumanA Called" << std::endl;
}

void HumanA::attack(){
	std::cout << this->_name << "attacks with their" << this->_weapon << std::endl;
}