/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:24:01 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/17 17:44:20 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

void Harl::switcher(std::string level) {
	void	(Harl::*fptr[])() = {&Harl::debug, &Harl::error, &Harl::info, &Harl::warning};
	std::string tab_com[] = {"DEBUG", "ERROR", "INFO", "WARNING"};
	int i = 0;

	switch (i < 4)
	{
		case (tab_com[i].compare(level) == 0)
	}()
}

void Harl::complain(std::string level) {
	void	(Harl::*fptr[])() = {&Harl::debug, &Harl::error, &Harl::info, &Harl::warning};
	std::string tab_com[] = {"DEBUG", "ERROR", "INFO", "WARNING"};

	for (int i = 0; i < 4; i++)
	{
		if (tab_com[i].compare(level) == 0){
			(this->*fptr[i])();
			return ;
		}
	}
	return ;
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
	std::cout << "Constructor of Harl Called" << std::endl;
}

Harl::~Harl( void ) {
	std::cout << "Destructor of Harl Called" << std::endl;
}
