/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:48:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/17 18:48:12 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int ac, char **av)
{
	(void)ac;
	if (ac != 2)
		return (std::cout << "Enter a argument please." << std::endl, 0);
	ScalarConverter::convert(av[1]);
	return (0);
}