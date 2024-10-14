/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:57:57 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/12 20:16:43 by grebrune         ###   ########.fr       */
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

void	PmergeMe::print_pair_vec(std::vector<std::pair< int , int > > V) {
	int i = 0;
	std::pair< int , int > pair;
	std::cout << "PAIR of " << V.size() << " elements :" << std::endl;
	for (std::vector<std::pair< int , int > >::iterator it=V.begin(); it!=V.end(); ++it) {
		pair = *it;
		std::cout << "First = " << pair.first << std::endl;
		std::cout << "Second = " << pair.second << std::endl;
		i++;
	}
}

void	PmergeMe::fill_vec() {
	if (_vec.size() < 2)
		throw BadArgument();
	for (size_t i = 0; i < _vec.size() -1 ; i += 2)
	{
		std::pair< int , int > pair;
		if (_vec[i] >= _vec[i + 1]) {
			pair.first = _vec[i + 1];
			pair.second = _vec[i];
		} else {
			pair.first = _vec[i];
			pair.second = _vec[i + 1];
		}
		_pair.push_back(pair);
	}
	print_pair_vec(_pair);
//	std::vector<int> sortedResult = fordJohnsonSortRecursive(_pair);
//	print_all(sortedResult);
}

int PmergeMe::jacobsthal(int n) {
	std::vector<int> J(n);
	if (n < 1)
		return 0;
	if (n < 2)
		return 1;
	else {
		J[0] = 0;
		J[1] = 1;
		for (int i = 2; i < n; ++i) {
			J[i] = J[i - 1] + (2 * J[i - 2]);
		}
	}
	for (size_t i = 0; i < J.size(); ++i) {
		std::cout << "J[" << i << "] =" << J[i] << std::endl;
	}
	std::cout << "J de n = " << J[n - 1] << std::endl;
	return (J[n - 1] + (2 * J[n - 2]));
}

void PmergeMe::vec_algo(char **av) {
	int n = 0;
	for (n = 0; av[n]; n++) {
		check_str(av[n]);
		_vec.push_back(std::atoi(av[n]));
	}
	fill_vec();
	recur(_pair, 0);
	print_all(_final);
}

void PmergeMe::print_all(std::vector<int> J) {
	int i = 0;
	std::cout << "RESULT of " << J.size() << " elements :" << std::endl;
	for (std::vector<int>::iterator it=J.begin(); it!=J.end(); ++it) {
		std::cout << "[" << i << "] = " << *it << std::endl;
		i++;
	}
}

void	PmergeMe::recur(std::vector< std::pair<int,int> > input, int n) {
	if (is_sort(input))
		return ;
	std::vector< std::pair<int,int> > to_next;
	for (size_t i = 0; i < input.size() - 1; i += 2) {
		std::pair<int, int> pair;
		if (input[i].second >= input[i + 1].second) {
			pair.second = input[i].second;
			pair.first = input[i + 1].second;
		} else {
			pair.second = input[i + 1].second;
			pair.first = input[i].second;
		}
		to_next.push_back(pair);
	}
	print_pair_vec(to_next);
	int j = jacobsthal(n);
	std::cout << "jacob = " << j << std::endl;
	recur(to_next, n + 1);
	if (_final.empty()) {
		_final.push_back(to_next[0].first);
		_final.push_back(to_next[0].second);
	}
//	else {
//		for (std::vector<std::pair<int ,int > >::iterator it = to_next.begin(); it < to_next.end(); it++) {
//			if (_final[j / 2] < it)
//			_final.push_back(to_next[j].first);
//		}
//	}
	return ;
}

bool PmergeMe::is_sort(std::vector<std::pair<int, int> > input) {
	for (size_t i = 0; i < input.size() - 1; i++) {
		if (input[i].first > input[i + 1].first)
			return false;
	}
	return true;
}

