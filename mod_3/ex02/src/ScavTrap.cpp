/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:42:55 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/05 17:19:05 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->_name = "default_name";
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdamage = 30;
	std::cout << "ScavTrap second constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	this->_name = name;
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &origine) : ClapTrap(origine) {
	std::cout << "ScavTrap Copy constructor operator called" << std::endl;
	*this = origine;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &origine) {
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this == &origine)
		return (*this);
	this->_name = origine._name;
	this->_hitpoints = origine._hitpoints;
	this->_energypoints = origine._energypoints;
	this->_attackdamage = origine._attackdamage;
	return (*this);
}

void ScavTrap::attack(const std::string &target) {
	if (this->_energypoints <= 0) {
		std::cout << "ScavTrap " << this->_name << " does not have enough energy points!" << std::endl;
		return ;
	}
	this->_energypoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackdamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}