/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/05 16:36:26 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default_name"), _hitpoints(10), _energypoints(10), _attackdamage(0) {
	std::cout << "ClapTrap second constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitpoints(10), _energypoints(10), _attackdamage(0) {
	this->_name = name;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Default destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &origine) {
	std::cout << "Copy constructor operator called" << std::endl;
	*this = origine;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &origine)
		return (*this);
	this->_hitpoints = origine._hitpoints;
	this->_energypoints = origine._energypoints;
	this->_attackdamage = origine._attackdamage;
	return (*this);
}

void ClapTrap::attack(const std::string &target) {
	if (this->_energypoints <= 0){
		std::cout << "ClapTrap " << this->_name << " does not have enough energy points!" << std::endl;
		return ;
	}
	this->_energypoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackdamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitpoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	this->_hitpoints = this->_hitpoints - amount;
	if (this->_hitpoints <= 0)
		std::cout << "ClapTrap " << this->_name << " died of pain!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energypoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " does not have enough energy points!" << std::endl;
		return ;
	}
	if (this->_hitpoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	this->_energypoints--;
	this->_hitpoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired by " << amount << ", he have now " << this->_hitpoints << " energy points!" << std::endl;
}
