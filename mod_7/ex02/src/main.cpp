/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:05:22 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/23 17:32:37 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	std::cout << "----------------BEGIN---------------" << std::endl;
	try {
		Array<> * a = new int();
		std::cout << "int *a = " << a;
		std::cout << a[10];
		*a = int(10);
		delete a;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: Index is out of bounds" << e.what() << " is the max." << std::endl;
	}
	std::cout << "----------------DISPLAY---------------" << std::endl;
	std::cout << "----------------END---------------" << std::endl;
}
