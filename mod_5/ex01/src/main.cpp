/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:42:23 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/05 14:31:12 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat k("kaan", 150);
		std::cout << k << std::endl;
		std::cout << "AAAAAAAAAA" << std::endl;
		Form f("Proce", 1, 140);
		std::cout << "BBBBBBBBBB" << std::endl;
		f.beSigned(k);
		std::cout << "CCCCCCCCCC" << std::endl;
		k.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exeption : " << e.what() << std::endl;
	}
}