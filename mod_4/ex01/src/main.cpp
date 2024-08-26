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
	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog();
	std::cout << "-------------Copy------------------" << " " << std::endl;
	*dog2 = *dog1;
	std::cout << "---------Destructor----------------" << " " << std::endl;
	delete dog1;
	delete dog2;
	std::cout << "---------End of Test---------------" << " " << std::endl;
	return 0;
}
