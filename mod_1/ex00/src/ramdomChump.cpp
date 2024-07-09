/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramdomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:08:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/09 19:43:59 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

void randomChump( std::string name ){
	std::string zob;

	zob = Zombie::Zombie(name);
	Zombie::annonce();
	Zombie::~Zombie();
	return ;
}