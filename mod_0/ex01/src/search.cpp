/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:21:38 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/07 17:28:34 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Friends.hpp"

void Contact::precision() {
	std::cout << "First Name     : " << FirstName << "\n";
	std::cout << "Last Name      : " << LastName << "\n";
	std::cout << "Nick Name      : " << NickName << "\n";
	std::cout << "Phone Number   : " << PhoneNumber << "\n";
	std::cout << "Darkest Secret : " << DarkestSecret << "\n";
}

void	PrintIndex(int index){
	int copy = index;
	int digits = 0;

	std::cout << "|";
	while (copy > 10){
		copy /= 10;
		digits++;
	}
	while (digits < 8){
		std::cout << " ";
		digits++;
	}
	std::cout << index << "|";
}

void	PrintStr(std::string str){
	std::size_t ctop;

	ctop = str.length();
	for (int printed = 0; printed + ctop < 10; printed++)
		std::cout << " ";
	for(int i = 0; i < 9 && str[i]; i++)
		std::cout << str[i];
	if (ctop >= 10)
		std::cout << ".";
	std::cout << "|";
}

void Contact::print(int index) {
	PrintIndex(index);
	PrintStr(FirstName);
	PrintStr(LastName);
	PrintStr(NickName);
	std::cout << "\n";
}

void PhoneBook::search() {
	int			number;
	std::string	preci;

	if (nbr_friends == 0)
	{
		std::cout << "You don't have any Friends yet :/" << std::endl;
		return ;
	}
	std::cout << "|  Index  |First Name| Last Name| Nick Name|" << std::endl;
	for (int i = 0; i <= index ; i++)
		friends[i].print(i);
	std::cout << "If you want additionnal information on a friend enter his index. If not type enter." << std::endl;
	getline(std::cin, preci);
	if (!preci.empty()){
		number = std::stoi(preci, NULL, 10) ;
		if (number >= 0 && number < nbr_friends)
			friends[number].precision();
		else
			std::cout << "Index not Found. ";
	}
	else
		std::cout << "Index not Found. ";
	std::cout << "Back on home, what do you want to do ?" << std::endl;
	return ;
}
