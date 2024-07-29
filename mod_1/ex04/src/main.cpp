/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:44:46 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/29 18:45:09 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	fill_fill_replace(std::ifstream& in_file, std::ofstream& outfile, std::string s1, std::string s2)
{
	std::string   format;

	while (getline(in_file, format))
	{
		std::size_t   posi = 0;
		while ((posi = format.find(s1, posi)) != std::string::npos)
		{
			format = format.substr(0 , posi) + s2 + format.substr(posi + s1.length());
			posi += s2.length();
		}
		outfile << format << '\n';
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
		return std::cout << "Wrong parameters" << std::endl, 1;

	std::ifstream in_file(av[1]);
	if (!in_file.is_open())
		 return std::cout << "Failed to open " << av[1] << std::endl, 1;

	std::string s1 = av[2];
	std::string s2 = av[3];
	if (s1.empty() || s2.empty())
		return std::cout << "A string can not be empty !" << std::endl, 1;

	std::string fileName(av[1]);
	fileName.append(".replace");
	std::ofstream outfile(fileName.c_str(), std::ios_base::out);

	fill_fill_replace(in_file, outfile, s1, s2);
}