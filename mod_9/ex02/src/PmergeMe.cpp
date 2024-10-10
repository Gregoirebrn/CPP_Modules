/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:57:57 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/10 18:59:02 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <algorithm>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &origin) {
	if (this != &origin) {
		_vec = origin._vec;
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &origin) {
	if (this != &origin) {
		_vec = origin._vec;
	}
	return *this;
}

PmergeMe::PmergeMe(char **av) {
	vec_algo(av);
//	deque(av);
}

void check_str(char *str) {
	for (int i = 0; str[i] ; ++i){
		if (!std::isdigit(str[i]))
			throw BadArgument();
	}
}

void PmergeMe::print_vec(){
	int i = 0;
	std::cout << "Vector of " << _vec.size() << " elements :" << std::endl;
	for (std::vector<int>::iterator it=_vec.begin(); it!=_vec.end(); ++it) {
		std::cout << "[" << i << "] = " << *it << std::endl;
		i++;
	}
}

void	PmergeMe::fill_vec() {
	if (_vec.size() < 2)
		throw BadArgument();
	for (size_t i = 0; i < _vec.size() -1 ; i += 2)
	{
		if (_vec[i] >= _vec[i + 1]) {
			_small.push_back(_vec[i + 1]);
			_big.push_back(_vec[i]);
		} else {
			_small.push_back(_vec[i]);
			_big.push_back(_vec[i + 1]);
		}
	}
}

void PmergeMe::vec_algo(char **av) {
	for (int i = 0; av[i]; i++) {
		check_str(av[i]);
		_vec.push_back(std::atoi(av[i]));
	}
	fill_vec();
	print_all();
}

void PmergeMe::print_all() {
	int i = 0;
	std::cout << "Base of " << _vec.size() << " elements :" << std::endl;
	for (std::vector<int>::iterator it=_vec.begin(); it!=_vec.end(); ++it) {
		std::cout << "[" << i << "] = " << *it << std::endl;
		i++;
	}
	i = 0;
	std::cout << "Big of " << _big.size() << " elements :" << std::endl;
	for (std::vector<int>::iterator it=_big.begin(); it!=_big.end(); ++it) {
		std::cout << "[" << i << "] = " << *it << std::endl;
		i++;
	}
	i = 0;
	std::cout << "Small of " << _small.size() << " elements :" << std::endl;
	for (std::vector<int>::iterator it=_small.begin(); it!=_small.end(); ++it) {
		std::cout << "[" << i << "] = " << *it << std::endl;
		i++;
	}
}

void	jacobsthal() {
	for (int i = 0; i < _n; ++i)

}

