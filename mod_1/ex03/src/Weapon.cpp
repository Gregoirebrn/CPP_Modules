/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:57:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/13 12:26:41 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon(std::string weap){

	this->_type = new_weap;
	std::cout << "Constructor of Weapon Called" << std::endl;
};

Weapon::~Weapon(){
	std::cout << "Destructor of Weapon Called" << std::endl;
}

const std::string Weapon::getType(){
	return this->_type;
}

void	Weapon::setType(std::string new_type){
	this->_type = new_type;
}
