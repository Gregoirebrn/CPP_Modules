/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:48:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 18:30:17 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
	std::srand(time(NULL));
	std::cout << "-------------------------------------------" << std::endl;

	Base *to_find = Base::generate();
	Base::identify(to_find);
	delete to_find;
	std::cout << "-------------------------------------------" << std::endl;

	Base *greg = Base::generate();
	Base::identify(greg);
	delete greg;
	std::cout << "-------------------------------------------" << std::endl;

	Base *ben = Base::generate();
	Base::identify(ben);
	delete ben;
	std::cout << "-------------------------------------------" << std::endl;
	return (0);
}