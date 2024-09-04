/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:16:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/05 16:42:13 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	std::cout << "---------------Constructor----------------" << std::endl;
	ClapTrap Ben("Ben");
	ClapTrap Kaan("Kaan");
	ClapTrap Greg("Greg");
	std::cout << "-------------------Tests------------------" << std::endl;
	Ben.attack("Kaan");
	Kaan.takeDamage(5);
	Kaan.beRepaired(4);
	Greg.attack("Ben");
	Ben.takeDamage(5);
	Ben.beRepaired(4);
	Kaan.attack("Greg");
	Greg.takeDamage(5);
	Greg.beRepaired(4);
	std::cout << "----------------Destructor----------------" << std::endl;
}
