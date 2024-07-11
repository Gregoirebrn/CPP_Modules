/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:08:31 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/10 13:42:20 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
//	Zombie zomben("Ben");
//	zomben.annonce();

	Zombie* zomkaa = newZombie("Kaan");
	randomChump("Greg");

	std::cout << "time has passed" << std::endl;

	delete zomkaa;
	return (0);
}
