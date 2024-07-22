/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:47:51 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/22 21:53:12 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <limits>

void PhoneBook::Creator() {
	_nbr_friends = 0;
	_index = 0;
}

void PhoneBook::new_contact() {
	if (_index == 8)
		_index = 0;
	if (_friends[_index].get_infos())
	{
		if (_nbr_friends < 8)
			_nbr_friends++;
		_index++;
		std::cout << "New Friend added. It's your " << _nbr_friends << " friend.\n";
	}
	else
		std::cout << "Wrong input !" <<std::endl;
	std::cout << "Back on home, what do you want to do ?" << std::endl;
	return ;
}

void PhoneBook::search() {
	int s_i;

	if (_nbr_friends == 0)
		return std::cout << "You don't have any Friends yet :/" << std::endl, void(0);
	std::cout << "|  Index  |First Name| Last Name| Nick Name|" << std::endl;
	for (int i = 0; i < _nbr_friends ; i++)
		_friends[i].print(i);
	std::cout << "If you want additionnal information on a friend enter his index. If not type enter." << std::endl << "> ";
	while (!(std::cin >> s_i)){
		if (std::cin.eof())
			return std::cout << "\nexit" << std::endl, void(0);
		std::cout << "Enter a number" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	if (s_i >= 0 && s_i < _nbr_friends){
		_friends[s_i].precision();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Index not Found. ";
	}
	std::cout << "Back on home, what do you want to do ?" << std::endl;
	return ;
}

