/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:14:22 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/19 18:49:19 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	int a = 7;
	int b = 14;

	std::cout << "----------------SWAP---------------" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	swap(a, b);
	std::cout << "             SWAPED                " << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "          ANOTHER ONE            " << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "             SWAPED                " << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "----------------MIN---------------" << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "min( a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "----------------MAX---------------" << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b) << std::endl;
	std::cout << "----------------END---------------" << std::endl;
}
