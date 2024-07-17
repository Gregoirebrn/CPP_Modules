/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:47:51 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/17 13:58:27 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

void PhoneBook::new_contact() {
	if (_nbr_friends == 8)
		_nbr_friends = 0;
	if (_friends[_nbr_friends].get_infos())
	{
		_nbr_friends++;
		_index = _nbr_friends - 1;
		std::cout << "New Friend added. It's your " << _nbr_friends << " friend.\n";
	}
	else
		std::cout << "Wrong input !" <<std::endl;
	std::cout << "Back on home, what do you want to do ?" << std::endl;
	return ;
}

void PhoneBook::Creator() {
	_nbr_friends = 0;
	_index = 0;
}

int	main(void)
{
	PhoneBook pb;
	std::string cmd;
	pb.Creator();
	std::cout << "Welcome in Friends, what do you want to do ?" <<std::endl;
	do
	{
		if (std::cin.eof())
			return (130);
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