/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:16:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/05 17:15:10 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
	std::cout << "---------------Constructor----------------" << std::endl;
	ClapTrap Ben("BEN");
	ClapTrap Kaan("KAAN");
	ScavTrap Greg("GOYO");

	std::cout << "-------------------Tests------------------" << std::endl;
	Ben.attack("KAAN");
	Kaan.takeDamage(5);
	Kaan.beRepaired(4);
	Greg.attack("BEN");
	Ben.takeDamage(5);
	Ben.beRepaired(4);
	Kaan.attack("GOYO");
	Greg.takeDamage(5);
	Greg.beRepaired(4);
	Greg.guardGate();

	std::cout << "----------------Destructor----------------" << std::endl;
}
