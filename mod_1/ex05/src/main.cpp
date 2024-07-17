/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:16:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/17 17:46:46 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(void)
{
	Harl Sreamer;
	Sreamer.complain("ERROR");
	Sreamer.complain("WARNING");
	Sreamer.complain("DEBUG");
	Sreamer.complain("INFO");
	Sreamer.complain("CACA");
	return std::cout << "Out of Complaints !" << std::endl, 0;
}
//	if (ac < 2)
//		return std::cout << "No Complaints to share ?" << std::endl, 1;
//	for (int i = 0; i < ac; i++)
//	{
//		Harl Sreamer;
//		Sreamer.complain(av[i]);
//	}
