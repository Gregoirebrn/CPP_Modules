/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:42:23 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 14:34:12 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try {
		std::cout << "---SHRUBBERY---" << std::endl;
		Bureaucrat first("Magelan", 130);
		ShrubberyCreationForm shrub("Kaan");
		std::cout << shrub << std::endl;
		std::cout << first << std::endl;
		first.signForm(shrub);
		shrub.execute(first);
		std::cout << "---ROBOTOMY---" << std::endl;
		const Bureaucrat sec("Hera", 20);
		RobotomyRequestForm roboto("Greg");
		std::cout << roboto << std::endl;
		std::cout << sec << std::endl;
		roboto.beSigned(sec);
		roboto.execute(sec);
		std::cout << "---PRESIDENTIAL---" << std::endl;
		const Bureaucrat third("Felon", 4);
		PresidentialPardonForm presi("Ben");
		std::cout << presi << std::endl;
		std::cout << third << std::endl;
		presi.beSigned(third);
		presi.execute(third);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exeption : " << e.what() << std::endl;
	}
}