/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:24:01 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/29 17:29:18 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int Harl::hash_level(std::string level) {
	unsigned int hash = 0;
	for (unsigned int i = 0; level[i]; i++){
		hash = hash * 43 + level[i];
	}
	return (hash);
}

void Harl::switcher(const std::string level) {
	void	(Harl::*fptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	switch (hash_level(level))
	{
		case 238090211: {
			for (int i = 0; i < 4; i++)
				(this->*fptr[i])();
			break;
		}
		case 5951322: {
			for (int i = 1; i < 4; i++)
				(this->*fptr[i])();
			break;
		}
		case 1455067208: {
			for (int i = 2; i < 4; i++)
				(this->*fptr[i])();
			break;
		}
		case 242571940: {
			for (int i = 3; i < 4; i++)
				(this->*fptr[i])();
			break;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl( void ){
}

Harl::~Harl( void ) {
}
