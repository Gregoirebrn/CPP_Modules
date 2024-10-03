/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:42:23 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 17:18:30 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Wrong number of argument." << std::endl, 0);
	ScalarConverter::convert(av[1]);
	std::cout << "           char" << std::endl;
	ScalarConverter::convert("z");
	std::cout << "           int" << std::endl;
	ScalarConverter::convert("10");
	std::cout << "           float" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << "           double" << std::endl;
	ScalarConverter::convert("21.0");
	std::cout << "           -inff" << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << "           +inff" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << "           nanf" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << "           -inf" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << "           +inf" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "           nan" << std::endl;
	ScalarConverter::convert("nan");


	return (0);
}