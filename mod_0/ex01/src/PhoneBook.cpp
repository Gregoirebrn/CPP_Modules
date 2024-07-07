/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:47:51 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/07 15:21:22 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PhoneBook.hpp"

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

void PhoneBook::new_contact() {
	if (nbr_friends == 8)
		nbr_friends = 0;
	if (friends[nbr_friends].get_infos())
	{
		nbr_friends++;
		std::cout << "New Friend added. It's your " << nbr_friends << " friend.\n";
	}
	else
		std::cout << "Wrong input !" <<std::endl;
	std::cout << "Back on home, what do you want to do ?" << std::endl;
	return ;
}

void PhoneBook::Creator() {
	nbr_friends = 0;
	index = 0;
}

int	main(void)
{
	PhoneBook pb;
	std::string cmd;
	pb.Creator();
	std::cout << "Welcome in friends, what do you want to do ?" <<std::endl;
	do
	{
		std::getline (std::cin,cmd);
		if (cmd == "ADD")
			pb.new_contact();
		else if (cmd == "SEARCH")
			pb.search();
		else if (cmd != "EXIT")
			std::cout << "PhoneBook: Command not found, try ADD, SEARCH or EXIT." <<std::endl;
	} while (cmd != "EXIT");
	//clear
	return (0);
}