/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/31 15:30:17 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter default destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &origine) {
	std::cout << "Copy constructor operator called" << std::endl;
	(void)origine;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void)origine;
	return (*this);
}

static void ToDouble(double d, unsigned long len) {
	int i = (int) d;

	if (d > 1.79768e+308)
		return (std::cout << "double: " << "+inf" << std::endl, (void)0);
	if (i == d && len <= 7)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

static void ToFloat(float f, unsigned long len) {
	int i = (int) f;

	if (i == f && len <= 7)
		std::cout << "float: " << f << ".0f"<< std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

static void ToInt(double i) {
	if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;
}

static void ToChar(double type, std::string str, int i) {
	if (type > 127)
		return (std::cout << "char: impossible" << std::endl, (void)0);
	if (i >= 9 && i <= 11)
			return (std::cout << "char: '" << static_cast<char>(type) << "'" << std::endl, (void)0);
	if (i > 0 && i < 32)
		return (std::cout << "char: Non displayable" << std::endl, (void)0);
	if (((str[0] < 32 || str[0] > 126) || str[0] == '0') && !str[1])
		std::cout << "char: Non displayable" << std::endl;
	else if (!str[1])
		std::cout << "char: '" << str[0] << "'" << std::endl;
	else
	{
		if (((char)type < 32 || (char)type > 126))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(type) << "'" << std::endl;
	}
}

static int spec_case(std::string str) {
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

static int check_cast(float f, std::string str) {
	std::ostringstream ss;
	ss << f;
	std::string s(ss.str());
	std::cout << "float f " << f << std::endl;
	std::cout << "float to String : " << s << std::endl;
	if (s == "+inf" || s == "inf" || s == "nanf" || s == "-inf")
		return 0;
	if (s != str)
		return 1;
	return 0;
}

void ScalarConverter::convert(std::string str)
{
	if (spec_case(str))
		return ;
	std::stringstream ss(str);
	double type;
	ss >> type;
	if (check_cast(static_cast<float>(type), str))
		return (putimp(), (void)0);
	ToChar(type, str, static_cast<int>(type));
	ToInt(type);
	ToFloat(static_cast<float>(type), str.length());
	ToDouble(type, str.length());
}
