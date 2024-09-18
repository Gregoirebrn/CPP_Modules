/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:48:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/18 14:49:20 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	std::cout << "--------------------------------------------------------------" << std::endl;
	Data test;
	test.exemple = 120;
	std::cout << "Data value = ----------------------" << test.exemple << std::endl;
	std::cout << "Data address =---------------------" << &test << std::endl;

	std::cout << "-------Serializer :" << std::endl;
	uintptr_t base;
	base = Serializer::serialize(&test);
	std::cout << "Serializer adresse uintptr_t = ----0x" << std::hex << base << std::endl;

	std::cout << "-----Deserializer :" << std::endl;
	Data *ret = Serializer::deserialize(base);
	std::cout << "Deserializer Data value =----------" << std::dec << ret->exemple << std::endl;
	std::cout << "Deserializer address =-------------" << ret << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	return (0);
}