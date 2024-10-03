/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:42:23 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 16:47:50 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat k("kaan", 150);
	std::cout << k << std::endl;
	std::cout << "---INCREMENT---" << std::endl;
	try{
		k.incr_grade();
	}
	catch (std::exception &e) {
		std::cerr << "Exception : " << e.what() << std::endl;
	}
	std::cout << k << std::endl;
	Bureaucrat g(k);
	std::cout << g << std::endl;
	std::cout << "---INCREMENT---" << std::endl;
	try{
	g.decr_grade();
	g.decr_grade();
	}
	catch (std::exception &e) {
		std::cerr << "Exception : " << e.what() << std::endl;
	}
	try{
	std::cout << g << std::endl;
	Bureaucrat b;
	g = b;
	std::cout << b << std::endl;
	std::cout << "---DECREMENT---" << std::endl;
	b.decr_grade();
	std::cout << b << std::endl;
	g.incr_grade();
	std::cout << g << std::endl;
	std::cout << g << std::endl;
	std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception : " << e.what() << std::endl;
	}
}