/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:02:13 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/13 12:08:06 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name){
	this->_name = name;
	std::cout << "Constructor of HumanB Called" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "Destructor of HumanB Called" << std::endl;
}

void HumanB::attack(){
	std::cout << this->_name << "attacks with their" << this->_weapon << std::endl;
}