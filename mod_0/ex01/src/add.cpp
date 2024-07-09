/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:24:42 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/09 18:28:41 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

Contact::Contact(void) {}

bool Contact::get_infos() {
	std::cout << "What is your first name ?" <<std::endl;
	std::getline(std::cin, _FirstName);
	if (_FirstName.empty())
		return (false);
	std::cout << "Your first name is " << _FirstName << ".\n";
	std::cout << "What is your last name ?" <<std::endl;
	std::getline(std::cin, _LastName);
	if (_LastName.empty())
		return (false);
	std::cout << "Your Last name is " << _LastName << ".\n";
	std::cout << "What is your nick name ?" <<std::endl;
	std::getline(std::cin, _NickName);
	if (_NickName.empty())
		return (false);
	std::cout << "Your nick name is " << _NickName << ".\n";
	std::cout << "What is your Phone Number ?" <<std::endl;
	std::getline(std::cin, _PhoneNumber);
	if (_PhoneNumber.empty())
		return (false);
	std::cout << "Your Phone Number is " << _PhoneNumber << ".\n";
	std::cout << "What is your Darkest Secret ?" <<std::endl;
	std::getline(std::cin, _DarkestSecret);
	if (_DarkestSecret.empty())
		return (false);
	std::cout << "Your Darkest Secret is " << _DarkestSecret << ".\n";
	return (true);
}
