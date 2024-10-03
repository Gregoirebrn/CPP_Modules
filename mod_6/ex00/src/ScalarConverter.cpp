/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:12:08 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 17:13:05 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter default destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &origin) {
	std::cout << "Copy constructor operator called" << std::endl;
	(void)origin;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void)origin;
	return (*this);
}

void print_types(char c, int i, float f, double d) {
	if (i > 127 || i < 0)
		std::cout << "char: impossible" << std::endl;
	else if (i < 9 || (i > 11 && i < 32) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (f < 1000000 && f > -1000000 && i - d == 0) {
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else {
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

static bool ToDouble(const std::string& str) {
	std::stringstream ss(str);
	double d;
	ss >> d;
	if (!ss.eof() || ss.fail())
		return (false);
	else {
		std::cout << "Is A Double" << std::endl;
		print_types(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
		return true;
	}
}

static bool ToFloat(std::string str) {
	std::stringstream ss(str);
	float f;
	ss >> f;
	if (ss.eof() || ss.fail() || str[str.length() - 1] != 'f')
		return (false);
	else {
		std::cout << "Is A Float" << std::endl;
		print_types(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
		return true;
	}
}

static bool ToInt(const std::string& str) {
	std::stringstream ss(str);
	int i;
	ss >> i;
	if (!ss.eof() || ss.fail())
		return (false);
	else {
		std::cout << "Is A Int" << std::endl;
		print_types(static_cast<int>(i), i, static_cast<float>(i), static_cast<double>(i));
		return true;
	}
}

static bool ToChar(std::string str) {
	if (str[1] || (str[0] >= '0' && str[0] <= '9'))
		return (false);
	else {
		std::cout << "Is A Char" << std::endl;
		print_types(str[0], static_cast<int>(str[0]), static_cast<float>(str[0]), static_cast<double>(str[0]));
		return true;
	}
}

static int spec_case(const std::string& str) {
	if(str == "nan" || str == "+inf" || str == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return 1;
	}
	if(str == "+inff" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, 4)<< std::endl;
		return 1;
	}
	if(str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, 3)<< std::endl;
		return 1;
	}
	return 0;
}

static void putimp() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& str) {
	if (ToChar(str))
		return (void)0;
	if (ToInt(str))
		return (void)0;
	if (ToFloat(str))
		return (void)0;
	if (ToDouble(str))
		return (void)0;
	if (spec_case(str))
		return ;
	putimp();
}
