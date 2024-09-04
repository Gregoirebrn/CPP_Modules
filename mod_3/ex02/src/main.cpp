/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:16:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/05 17:40:27 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	std::cout << "---------------Constructor----------------" << std::endl;
	ClapTrap Ben("BEN");
	ScavTrap Greg("GOYO");
	FragTrap Kaan("KAAN");

	std::cout << "-------------------Tests------------------" << std::endl;
	Ben.attack("KAAN");
	Kaan.takeDamage(0);
	Kaan.beRepaired(4);
	Greg.attack("BEN");
	Ben.takeDamage(20);
	Ben.beRepaired(4);
	Kaan.attack("GOYO");
	Greg.takeDamage(30);
	Greg.beRepaired(4);
	Kaan.highFivesGuys();
	std::cout << "----------------Destructor----------------" << std::endl;
}
