/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:42:55 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/05 17:21:12 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->_name = "default_name";
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdamage = 30;
	std::cout << "FragTrap second constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) {
	this->_name = name;
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &origine) : ClapTrap(origine) {
	std::cout << "FragTrap Copy constructor operator called" << std::endl;
	*this = origine;
}

FragTrap &FragTrap::operator=(const FragTrap &origine) {
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this == &origine)
		return (*this);
	this->_name = origine._name;
	this->_hitpoints = origine._hitpoints;
	this->_energypoints = origine._energypoints;
	this->_attackdamage = origine._attackdamage;
	return (*this);
}

void FragTrap::attack(const std::string &target) {
	if (this->_energypoints <= 0) {
		std::cout << "FragTrap " << this->_name << " does not have enough energy points!" << std::endl;
		return ;
	}
	this->_energypoints--;
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackdamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name << " say High Fives Guys!" << std::endl;
}