/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:12:56 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 17:13:05 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <bits/stdc++.h>

class ScalarConverter{
private:
	ScalarConverter();
	~ScalarConverter();
public:
	ScalarConverter (const ScalarConverter &origin);
	ScalarConverter &operator=(const ScalarConverter &origin);

	static void convert(const std::string& str);
};

#endif
