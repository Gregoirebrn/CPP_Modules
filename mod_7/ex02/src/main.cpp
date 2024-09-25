/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:05:22 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/25 18:50:11 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main() {

	{
		std::size_t size = 12;
		Array<unsigned int> tab(size);
		Array<unsigned int> tab2(size * 2);

		tab = tab2;

	}
//	return (0);
	{
		unsigned int		size = 12;
		Array<std::string>	test(size);

		std::cout << "size = " << test.size() << std::endl;
		try {
			for (unsigned int i = 0; i < test.size(); i++) {
				test[i] = "hey";
			}
			std::cout << "11 = " << test[11] << std::endl;
			test[11] = "salut";
			std::cout << "11 = " << test[11] << std::endl;
			for (unsigned int i = 0; i < test.size(); i++) {
				std::cout << i << " = " << test[i] << std::endl;
			}
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
		try {
			std::cout << "-1 = " << test[-1] << std::endl;
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
		try {
			std::cout << "13 = " << test[13] << std::endl;
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
		try {
			std::cout << "12 = " << test[12] << std::endl;
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
	}
	{
		unsigned int	size = 12;
		Array<int>		test(size);

		std::cout << "size = " << test.size() << std::endl;
		try {
			std::cout << "11 = " << test[11] << std::endl;
			for (unsigned int i = 0; i < test.size() ; i++) {
				test[i] = 42;
			}
			std::cout << "11 = " << test[11] << std::endl;
			test[11] = 97;
			std::cout << "11 = " << test[11] << std::endl;
			for (unsigned int i = 0; i < test.size() ; i++) {
				std::cout << i << " = " << test[i] << std::endl;
			}
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
		try {
			std::cout << "-1 = " << test[-1] << std::endl;
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
		try {
			std::cout << "13 = " << test[13] << std::endl;
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
	}
	{
		unsigned int	size = 12;
		Array<float>	test(size);

		std::cout << "size = " << test.size() << std::endl;
		try {
			std::cout << "11 = " << test[11] << std::endl;
			for (unsigned int i = 0; i < test.size() ; i++) {
				test[i] = 42.42;
			}
			std::cout << "11 = " << test[11] << std::endl;
			test[11] = 19.97;
			std::cout << "11 = " << test[11] << std::endl;
			for (unsigned int i = 0; i < test.size() ; i++) {
				std::cout << i << " = " << test[i] << std::endl;
			}
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
		try {
			std::cout << "-1 = " << test[-1] << std::endl;
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
		try {
			std::cout << "13 = " << test[13] << std::endl;
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
	}
	{
		Array<int>	test;

		std::cout << "size = " << test.size() << std::endl;
		try {
			std::cout << "0 = " << test[0] << std::endl;
			for (unsigned int i = 0; i < test.size() ; i++) {
				test[i] = 42;
			}
			std::cout << "11 = " << test[11] << std::endl;
			test[11] = 97;
			std::cout << "11 = " << test[11] << std::endl;
			for (unsigned int i = 0; i < test.size() ; i++) {
				std::cout << i << " = " << test[i] << std::endl;
			}
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
		try {
			std::cout << "-1 = " << test[-1] << std::endl;
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
		try {
			std::cout << "13 = " << test[13] << std::endl;
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
	}
	{
		unsigned int		size = 4;
		Array<Array<int> >	test(size);

		std::cout << "size = " << test.size() << std::endl;
		try {
			for (unsigned int i = 0; i < test.size(); ++i) {
				std::cout << "size["<<i<<"] = " << test[1].size() << std::endl;
			}
			for (unsigned int i = 0; i < test.size(); ++i) {
				for (unsigned int j = 0; j < test[i].size(); ++j) {
					test[i][j] = i + j;
				}
			}
			for (unsigned int i = 0; i < test.size(); ++i) {
				for (unsigned int j = 0; j < test[i].size(); ++j) {
					std::cout << "test["<<i<<"]["<<j<<"] = "<<test[i][j] << std::endl;
				}
			}
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
		try {
			std::cout << "-1 = " << test[-1][0] << std::endl;
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
		try {
			std::cout << "5 = " << test[13][0] << std::endl;
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
	}
	{
		Array<int>	*a = new Array<int>();
		int			*b = new int();

		std::cout << "*a is: " << &a << std::endl;
		std::cout << "*a is: " << a << std::endl;
		std::cout << "*b is: " << &b << std::endl;
		std::cout << "*b is: " << b << std::endl;
		delete a;
		delete b;
	}
	{
		Array<float>	test(12);
		try {
			std::cout << "size = " << test.size() << std::endl;
			std::cout << "default test [11] = "  << test[11] << std::endl;
			for  (unsigned int i = 0; i < test.size() ; i++) {
				test[i] = 42.42;
			}
			std::cout << "1st init test [11] = " << test[11] << std::endl;
			test[11] = 19.97;
			std::cout << "2nd init test [11] = " << test[11] << std::endl;
			for  (unsigned int i = 0; i < test.size() ; i++) {
				std::cout<< "test ["<< i << "] = " << test[i] << std::endl;
			}
		}
		catch (std::exception &error) {
			std::cout << error.what() << std::endl;
		}
		Array<float>	cpy(test);
		Array<float>	cpy2 = cpy;
		for  (unsigned int i = 0; i < cpy.size() ; i++) {
			std::cout << "cpy ["<< i << "] = " << cpy[i] << std::endl;
		}
		for  (unsigned int i = 0; i < cpy2.size() ; i++) {
			std::cout << "cpy2 ["<< i << "] = " << cpy2[i] << std::endl;
		}
		std::cout << "modifying cpy2" << std::endl;
		cpy2[3] = 12.54;
		for  (unsigned int i = 0; i < test.size() ; i++) {
			std::cout<< "test ["<< i << "] = " << test[i] << std::endl;
		}
		for  (unsigned int i = 0; i < cpy.size() ; i++) {
			std::cout << "cpy ["<< i << "] = " << cpy[i] << std::endl;
		}
		for  (unsigned int i = 0; i < cpy2.size() ; i++) {
			std::cout << "cpy2 ["<< i << "] = " << cpy2[i] << std::endl;
		}
	}
}
