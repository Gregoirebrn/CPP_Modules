/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:49:26 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/05 19:42:21 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

std::string ft_upp(std::string low)
{
	for(int i = 0; low[i]; i++)
		low[i] = toupper(low[i]);
	return (low);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
		std::cout <<ft_upp(av[i]);
	std::cout << std::endl;
	return (0);
}