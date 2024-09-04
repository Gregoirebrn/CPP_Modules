/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:42:23 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/04 17:58:13 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat k("kaan", 150);
//		std::cout << k << std::endl;
//		k.incr_grade(4);
		std::cout << k << std::endl;
		Bureaucrat g("greg", 130);
		std::cout << g << std::endl;
		g.incr_grade(4);
		std::cout << g << std::endl;
		Bureaucrat b("ben", 0);
		std::cout << b << std::endl;
		b.decr_grade(2);
		std::cout << b << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Exeption : " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exeption : " << e.what() << std::endl;
	}
}