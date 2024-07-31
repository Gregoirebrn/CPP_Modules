/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:42:55 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/31 11:14:21 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	this->_name = "default_name";
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
	this->_name = name;
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
	std::cout << "DiamondTrap second constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &origine) {
	std::cout << "Copy constructor operator called" << std::endl;
	this->_hitpoints = origine._hitpoints;
	this->_energypoints = origine._energypoints;
	this->_attackdamage = origine._attackdamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origine)
		return (*this);
	this->_name = origine._name;
	this->_hitpoints = origine._hitpoints;
	this->_energypoints = origine._energypoints;
	this->_attackdamage = origine._attackdamage;
	return (*this);
}

void DiamondTrap::attack(const std::string &target) {
	if (this->_energypoints <= 0)
		std::cout << "DiamondTrap " << this->_name << " does not have enough energy points!" << std::endl;
	this->_energypoints--;
	std::cout << "DiamondTrap " << this->_name << " attacks " << target << ", causing " << this->_attackdamage << " points of damage!" << std::endl;
}

void DiamondTrap::highFivesGuys() {
	std::cout << "DiamondTrap " << this->_name << " say High Fives Guys!" << std::endl;
}
void DiamondTrap::whoAmI() {
	std::cout << "This is " << this->_name << " speaking, I AM DIAMOND!" << std::endl;
}