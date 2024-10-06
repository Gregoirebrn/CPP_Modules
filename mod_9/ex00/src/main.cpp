/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:14:22 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/06 19:29:14 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
//	if (ac != 2)
//		return (std::cout << "Missing file argument !" << std::endl, 0);
	(void)ac;
	(void)av;
//	try {
//		BitcoinExchange btc((av[1]));
//	}
//	catch (std::exception &e) {
//		std::cerr << "Error: " << e.what() << std::endl;
//	}
	BitcoinExchange btc;
	BitcoinExchange copy = btc;
	for (std::map<std::string, double>::const_iterator it = copy._map.begin() ; it != copy._map.end() ; ++it) {
		this->_map[it->first] = it->second;
	}

	return 0;
}