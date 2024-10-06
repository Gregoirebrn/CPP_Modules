
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
	std::map<std::string, double> _map;
public:
	BitcoinExchange();
	BitcoinExchange (const char *file_name);
	~BitcoinExchange() {}
	BitcoinExchange (const BitcoinExchange &origin);
	BitcoinExchange &operator=(const BitcoinExchange &origin);

	void	check_value(double value);
	void	check_date(std::string date);
	void	get_csv();
	void	get_val_btc(std::string date, double value);

	void print_map();

	class ErrorFile : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("could not open file.");
		}
	};

	class WrongDate : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("date is lower then the beginning of the Bitcoin .");
		}
	};

	class ValueTooHigh : public std::exception {
	public:
		const char* what() const throw() {
			return ("too large a number.");
		}
	};

	class ValueTooLow : public std::exception {
	public:
		const char* what() const throw() {
			return ("not a positive number.");
		}
	};

};

#endif
