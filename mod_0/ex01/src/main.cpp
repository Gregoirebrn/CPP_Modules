/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:21:38 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/22 20:47:22 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

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
	return (0);
}
