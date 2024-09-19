/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:14:22 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/19 19:38:22 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename K>
void	kar(K &c)
{
	c = 50;
}


int main(void)
{
	char array[10];
	std::cout << "----------------BEGIN---------------" << std::endl;
	for(int i = 0; i < 10; i++) {
		array[i] = i + 48;
		std::cout << "At array "<< i << " = " << array[i] << std::endl;
	}
	std::cout << "----------------ITER---------------" << std::endl;
	iter(array, 10, &kar<char>);
	std::cout << "--------------ITERETED-------------" << std::endl;
	for(int i = 0; i < 10; i++) {
		std::cout << "At array "<< i << " = " << array[i] << std::endl;
	}
	std::cout << "----------------END---------------" << std::endl;
}
