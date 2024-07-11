/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:42:22 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/10 13:48:42 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* newZombie( std::string name ){
	Zombie* Greg = new Zombie(name);
	std::cout << Greg->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return Greg;
}