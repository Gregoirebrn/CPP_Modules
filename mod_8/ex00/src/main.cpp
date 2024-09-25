/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:05:22 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/25 20:50:52 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
//init vector
	std::vector<int> number;
	int tab[] = {1, 100, 1070, 7010, 70};
	number.insert(number.end(), tab, tab + 5);
//print list of integers
	std::cout << "Numbers are: " << std::endl;
	for(size_t i = 0; i < number.size();  i++) {
		std::cout << "At [" << i << "]= " << number[i] << std::endl;
	}
//find first occurence with integers
	try {
		find_or_not(number, 70);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//find first occurence with strings
//	std::vector<int> chr;
//	std::string str = "hellloooo";
//	chr.insert(chr.end(), str, str + 5);
//	try {
//		find_or_not(str, 'h');
//	}
//	catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}
	return 0;
}
