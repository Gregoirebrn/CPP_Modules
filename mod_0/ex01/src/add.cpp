/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:24:42 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/07 15:31:17 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Friends.hpp"

Contact::Contact(void) {}

bool Contact::get_infos() {
	std::cout << "What is your first name ?" <<std::endl;
	std::getline(std::cin, FirstName);
	if (FirstName.empty())
		return (false);
	std::cout << "Your first name is " << FirstName << ".\n";
	std::cout << "What is your last name ?" <<std::endl;
	std::getline(std::cin, LastName);
	if (LastName.empty())
		return (false);
	std::cout << "Your Last name is " << LastName << ".\n";
	std::cout << "What is your nick name ?" <<std::endl;
	std::getline(std::cin, NickName);
	if (NickName.empty())
		return (false);
	std::cout << "Your nick name is " << NickName << ".\n";
	std::cout << "What is your Phone Number ?" <<std::endl;
	std::getline(std::cin, PhoneNumber);
	if (PhoneNumber.empty())
		return (false);
	std::cout << "Your Phone Number is " << PhoneNumber << ".\n";
	std::cout << "What is your Darkest Secret ?" <<std::endl;
	std::getline(std::cin, DarkestSecret);
	if (DarkestSecret.empty())
		return (false);
	std::cout << "Your Darkest Secret is " << DarkestSecret << ".\n";
	return (true);
}
