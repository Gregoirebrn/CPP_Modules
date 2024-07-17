/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:44:46 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/17 14:44:54 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
# include <string>

void	fill_fill_replace(std::ifstream& in_file, std::ofstream& outfile, std::string s1, std::string s2)
{
	std::string   format = NULL;
	std::size_t   posi = 0;

	while (getline(in_file, format))
	{
		while (posi == s2.find(s1, posi))
		{
			format = format.substr(posi) + s2 + format.substr(posi + s1.length());
		}
		outfile << format << '\n';
	}
	in_file.close();
	outfile.close();
}

int main(int ac, char **av)
{
	if (ac < 4 || ac > 4)
		return std::cout << "Wrong parameters" << std::endl, 1;
	std::ifstream in_file(av[1]);
	std::string fileName(av[1]);
	fileName.append(".replace");
	std::ofstream outfile(fileName.c_str(), std::ios_base::out);
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (!in_file.is_open())
		std::cout << "Failed to open " << av[1] << std::endl;
	fill_fill_replace(in_file, outfile, s1, s2);
}