/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:43:03 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/06 19:37:18 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	get_csv();
}

BitcoinExchange::BitcoinExchange(const char *file_name) {
	get_csv();
	std::ifstream file((const char *) file_name);

	if (!file.is_open())
		throw BitcoinExchange::ErrorFile();
	std::string line;
	if (std::getline(file, line)) {
	}
	while (std::getline(file, line))
	{
		std::istringstream stream(line);
		std::string date;
		double value;

		if (std::getline(stream, date, '|') && (stream >> value)) {
			try {
				check_date(date);
				check_value(value);
				get_val_btc(date, value);
			}
			catch (std::exception &e) {
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &origin) {

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &origin) {
	if (this != &origin) {
		for (std::map<std::string, double>::const_iterator it = origin._map.begin() ; it != origin._map.end() ; ++it) {
			this->_map[it->first] = it->second;
		}
	}
	return *this;
}

void BitcoinExchange::get_csv() {
	std::ifstream file("data.csv");

	if (!file.is_open())
		throw BitcoinExchange::ErrorFile();
	std::string line;
	if (std::getline(file, line)) {
	}
	while (std::getline(file, line))
	{
		std::istringstream stream(line);
		std::string date;
		double value;

		if (std::getline(stream, date, ',') && (stream >> value))
			_map[date] = value;
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	file.close();
}

void BitcoinExchange::check_date(std::string date) {
	int y = std::atoi(date.c_str());
	if (y > 2024 || y < 2009) {
		throw BitcoinExchange::WrongDate();
	}
	int i = date.find('-', 0) + 1;
	date = &date[i];
	int m = std::atoi(date.c_str());
	if (m > 12 || m < 1) {
		throw BitcoinExchange::WrongDate();
	}
	i = date.find('-', i) + 4;
	date = &date[i];
	int d = std::atoi(date.c_str());
	if (d > 31 || d < 1 || (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11)) || (m == 2 && d > 28 && (!(d == 29 && y % 4 == 0))))
		throw BitcoinExchange::WrongDate();
}

void BitcoinExchange::check_value(double value) {
	if (value > 1000)
		throw BitcoinExchange::ValueTooHigh();
	if (value < 0)
		throw BitcoinExchange::ValueTooLow();
}

void BitcoinExchange::get_val_btc(std::string date, double value) {
	std::map<std::string, double>::iterator it = _map.find(date);
	if (it != _map.end()) {
		std::cout << it->first << " => " << value << " = " << (it->second * value) << std::endl;
	}
	else
	{
		it = _map.lower_bound(date);
		if (it != _map.begin()) {
			--it;
			std::cout << it->first << " => " << value << " = " << (it->second * value) << std::endl;
		}
		else
			BitcoinExchange::WrongDate();
	}
}

void BitcoinExchange::print_map() {
	for (std::map<std::string, double>::const_iterator it = _map.begin() ; it != _map.end() ; ++it) {
		this->_map[it->first] = it->second;
	}
}
