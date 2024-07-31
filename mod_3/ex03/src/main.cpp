/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:16:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/31 10:35:48 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap Ben("BEN");
	ClapTrap Kaan("KAAN");
	ScavTrap Greg("GOYO");

	Ben.attack("KAAN");
	Kaan.takeDamage(5);
	Kaan.beRepaired(4);
	Greg.attack("BEN");
	Ben.takeDamage(5);
	Ben.beRepaired(4);
	Kaan.attack("GOYO");
	Greg.takeDamage(5);
	Greg.beRepaired(4);
}
