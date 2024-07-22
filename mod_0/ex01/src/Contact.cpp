/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:24:42 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/22 21:05:40 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <iomanip>

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

std::string Contact::prtstr(std::string str)
{
	if (str.size() > 10){
		str.resize(9);
		str = str + '.';
	}
	return str;
}

void Contact::print(int index) {
	std::cout << "|" << std::right << std::setw(9) << index << "|";
	std::cout.width(10); std::cout << std::right << prtstr(this->_FirstName) << "|";
	std::cout.width(10); std::cout << std::right << prtstr(this->_LastName) << "|";
	std::cout.width(10); std::cout << std::right << prtstr(this->_NickName) << "|";
	std::cout << std::endl;
}

void Contact::precision() {
	std::cout << "First Name     : " << _FirstName << std::endl;
	std::cout << "Last Name      : " << _LastName << std::endl;
	std::cout << "Nick Name      : " << _NickName << std::endl;
	std::cout << "Phone Number   : " << _PhoneNumber << std::endl;
	std::cout << "Darkest Secret : " << _DarkestSecret << std::endl;
}
