/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:16:19 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/01 13:43:40 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "---------Constructor---------------" << " " << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "---------Destructor----------------" << " " << std::endl;
	delete j;//should not create a leak
	delete i;
	std::cout << "---------End of Test---------------" << " " << std::endl;
	return 0;
}
