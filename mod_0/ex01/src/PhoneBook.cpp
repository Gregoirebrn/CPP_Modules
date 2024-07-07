/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:47:51 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/07 17:08:06 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Friends.hpp"

void PhoneBook::new_contact() {
	if (nbr_friends == 8)
		nbr_friends = 0;
	if (friends[nbr_friends].get_infos())
	{
		nbr_friends++;
		index = nbr_friends - 1;
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