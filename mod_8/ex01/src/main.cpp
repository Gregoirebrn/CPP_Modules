/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:46:47 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/28 16:27:18 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try {
	Span sp = Span(5);
	sp.addNumber(3);
	sp.addNumber(123);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.print_vec();
	std::cout << "Shortest = " << sp.shortestSpan() << std::endl;
	std::cout << "Longest = " << sp.longestSpan() << std::endl;

	Span op = sp;
	op.print_vec();
	std::cout << "Shortest = " << op.shortestSpan() << std::endl;
	std::cout << "Longest = " << op.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exepction: " << e.what() << std::endl;
	}
	return 0;
}
