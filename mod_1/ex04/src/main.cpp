/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:44:46 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/15 17:20:59 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
# include <string>


int main(int ac, char **av)
{
	std::ifstream in_file;
	std::ofstream out_file;
	std::string   format;
	if (ac < 4 || ac > 4)
		return std::cout << "Wrong parameters" << std::endl, 1;
	in_file.open(av[1]);
	std::ofstream outfile("out_file");
	if (in_file.is_open())
	{
		while (getline(in_file, format))
		{
			out_file << format << '\n';
		}
		in_file.close();
	}
}