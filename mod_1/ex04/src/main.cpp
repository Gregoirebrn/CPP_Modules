/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:44:46 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/16 17:12:07 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
# include <string>

void	fill_fill_replace(std::string file_name, std::string format)
{
	std::ifstream in_file(file_name);
	std::ofstream outfile(file_name + ".replace");

	if (in_file.is_open())
	{
		while (getline(in_file, format))
		{
			outfile << format << '\n';
		}
		in_file.close();
		outfile.close();
	}
}

int main(int ac, char **av)
{
	std::ifstream in_file(av[1]);
	std::string   format;

	if (ac < 4 || ac > 4)
		return std::cout << "Wrong parameters" << std::endl, 1;
	if (!in_file.is_open())
		std::cout << "Failed to open " << av[1] << std::endl;
	fill_fill_replace(av[1], format);
}