/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:48:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/19 12:33:14 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
	srand(time(NULL));
	std::cout << "-------------------------------------------" << std::endl;

	Base *to_find = Base::generate();
	Base::identify(to_find);

	delete to_find;
	std::cout << "-------------------------------------------" << std::endl;
	return (0);
}