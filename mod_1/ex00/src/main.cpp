/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:08:31 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/09 19:36:41 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

int	main(void)
{
	Zombie zomben("Ben");
	zomben.annonce();

	Zombie* zomkaa = newZombie("Kaan");
	zomkaa->annonce();
	delete zomkaa;

	randomChump("Greg");
	return (0);
}
