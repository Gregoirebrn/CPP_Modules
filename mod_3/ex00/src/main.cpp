/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:16:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/30 16:24:08 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap Ben;
	ClapTrap Kaan;
	ClapTrap Greg;

	Ben.attack("Kaan");
	Kaan.takeDamage(5);
	Kaan.beRepaired(4);
	Greg.attack("Ben");
	Ben.takeDamage(5);
	Ben.beRepaired(4);
	Kaan.attack("Greg");
	Greg.takeDamage(5);
	Greg.beRepaired(4);
}
