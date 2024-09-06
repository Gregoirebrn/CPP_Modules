/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:42:23 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/06 18:56:54 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
		const Bureaucrat first("kaan", 150);
		std::cout << "AAAAAAAAAA" << std::endl;
		ShrubberyCreationForm shrub("kaan");
		std::cout << "BBBBBBBBBB" << std::endl;
		shrub.execute(first);
		std::cout << "CCCCCCCCCC" << std::endl;
//	}
//	catch (std::exception &e)
//	{
//		std::cerr << "Exeption : " << e.what() << std::endl;
//	}
}