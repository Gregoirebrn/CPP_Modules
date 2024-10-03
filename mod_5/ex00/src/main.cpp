/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:42:23 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/02 14:38:27 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat k("kaan", 150);
		std::cout << k << std::endl;
		std::cout << "---INCREMENT---" << std::endl;
		k.incr_grade();
		std::cout << k << std::endl;
		Bureaucrat g(k);
		std::cout << g << std::endl;
		std::cout << "---INCREMENT---" << std::endl;
		g.incr_grade();
		std::cout << g << std::endl;
		Bureaucrat b("ben", 1);
		std::cout << b << std::endl;
		std::cout << "---DECREMENT---" << std::endl;
		b.incr_grade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exeption : " << e.what() << std::endl;
	}
}