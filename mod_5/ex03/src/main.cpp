/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:42:23 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/02 17:09:37 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try {
		Intern someRandomIntern;
		std::cout << "---ROBOTOMY---" << std::endl;
		AForm* robo;
		robo = someRandomIntern.makeForm("robotomy request", "Bender");

		std::cout << "---PRESIDENTIAL---" << std::endl;
		AForm* pres;
		pres = someRandomIntern.makeForm("presidential pardon", "Fudg");

		std::cout << "---SHRUBBERY---" << std::endl;
		AForm* shrub;
		shrub = someRandomIntern.makeForm("shrubbery creation", "Mondu");

		std::cout << "---DEFAULT---" << std::endl;
		robo = someRandomIntern.makeForm("rob", "Bender");
	}
	catch (std::exception &e)
	{
		std::cerr << "Exeption : " << e.what() << std::endl;
	}
}