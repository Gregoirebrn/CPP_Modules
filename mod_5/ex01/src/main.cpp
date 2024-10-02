/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:42:23 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/02 15:44:41 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat k("kaan", 13);
		std::cout << k << std::endl;
		Form f("Proce", 120, 140);
		std::cout << f << std::endl;
		f.beSigned(k);
		std::cout << f << std::endl;
		k.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << "Exeption : " << e.what() << std::endl;
	}
}