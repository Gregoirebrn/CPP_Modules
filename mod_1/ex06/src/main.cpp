/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:16:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/29 17:28:34 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		return std::cout << "No Complaints to share ?" << std::endl, 1;
	Harl Sreamer;
	Sreamer.switcher(av[1]);
	return 0;
}
