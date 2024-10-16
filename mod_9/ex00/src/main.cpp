/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:14:22 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/07 11:03:53 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
//	if (ac != 2)
//		return (std::cout << "Missing file argument !" << std::endl, 0);
	(void)ac;
//	(void)av;
	try {
		BitcoinExchange btc((av[1]));
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
//	BitcoinExchange *copy = NULL;
//	copy->print_map();

	return 0;
}