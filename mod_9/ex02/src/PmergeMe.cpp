/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:57:57 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/14 17:27:03 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <complex>
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

PmergeMe::PmergeMe(char **av) : _jacob_number(0){
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

void PmergeMe::print_all(std::vector<int> J) {
	int i = 0;
	std::cout << "RESULT of " << J.size() << " elements :" << std::endl;
	for (std::vector<int>::iterator it=J.begin(); it!=J.end(); ++it) {
		std::cout << "[" << i << "] = " << *it << std::endl;
		i++;
	}
}

void PmergeMe::vec_algo(char **av) {
	int n = 0;
	for (n = 0; av[n]; n++) {
		check_str(av[n]);
		_vec.push_back(std::atoi(av[n]));
	}
	fill_vec();
	recur(_pair);
	print_all(_final);
}

size_t PmergeMe::jacobsthal(int idx) {
	if (idx == 0)
		return 0;
	return (static_cast<std::size_t>(std::pow(2, idx + 1)) + static_cast<std::size_t>(std::pow(-1, idx))) / 3;
}

void	PmergeMe::recur(std::vector< std::pair<int,int> > input) {
	if (is_sort(input)) {
		_final.push_back(input[0].first);
		_final.push_back(input[0].second);
		return ;
	}
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
	recur(to_next);
	if (1 == to_next.size())
		return ;

	size_t dist = jacobsthal(++_jacob_number);
	std::cout << "first Dist = " << dist << std::endl;
	if (dist > _final.size())
		dist = _final.size() - 1 ;
	print_pair_vec(to_next);
	size_t last_jacob_number = jacobsthal(_jacob_number - 1);
	std::cout << "size = " << to_next.size() << std::endl;
	std::cout << "Jacob Number =" << _jacob_number << std::endl;
	std::cout << "Last Jacob Number =" << last_jacob_number << std::endl;


	while (dist >= last_jacob_number) {
	std::cout << "Dist = " << dist << std::endl;
		int i = find_small(to_next, _final[dist]);
				std::cout << "7" << std::endl;
//			print_all(_final);
		if (i == -1) {
			std::cout << "i  = " << i << "next first value " << to_next[i].first << std::endl;
			i = find_small(to_next, _final[dist + 1]);
			std::cout << "i  = " << i << "next first value " << to_next[i].first << std::endl;
		}
			std::cout << "i  = " << i << "next first value " << to_next[i].first << std::endl;
		for(std::vector<int>::iterator it=_final.begin() + jacobsthal(_jacob_number); it!=_final.begin(); --it) {
			std::cout << "iterator value = " << *it << std::endl;
			if (*it > to_next[i].first && ( it == _final.begin() || *(it - 1) < to_next[i].first)) {
				std::cout << "fTTTTTTTTTT = " << std::endl;
				_final.insert(it, to_next[i].first);
				break;
			}
				std::cout << "UUUUUUUUUUUUU = " << std::endl;
			if ((it - 1) == _final.begin()) {
				_final.insert((it - 1), to_next[i].first);
				std::cout << "6" << std::endl;
			print_all(_final);
			std::cout << "frrrrrrrrrre = " << std::endl;
//				to_next.erase(find_iter(to_next, i));
				break;
			}
		}
		if (dist == 0) {
				std::cout << "5" << std::endl;
			print_all(_final);
			return;
		}
		dist--;
	}
	std::cout << "Final end of recur" << std::endl;
}

std::vector<std::pair< int , int > >::iterator PmergeMe::find_iter(std::vector<std::pair< int , int > > V, int i) {
	int find = 0;
	for (std::vector<std::pair< int , int > >::iterator it = V.begin(); it != V.end(); it++) {
		if (find == i)
			return it;
		find++;
	}
	std::vector<std::pair< int , int > >::iterator it = V.end();
	return it;
}
//			std::cout << "BBB" << std::endl;
//		std::cout << "AAA" << std::endl;

	//rest of elements
//	else {
//		for (std::vector<std::pair<int ,int > >::iterator it = to_next.begin(); it < to_next.end(); it++) {
//			if (_final[j / 2] < it)
//			_final.push_back(to_next[j].first);
//		}
//	}

bool PmergeMe::is_sort(std::vector<std::pair<int, int> > input) {
	for (size_t i = 0; i < input.size() - 1; i++) {
		if (input[i].first > input[i + 1].first)
			return false;
	}
	return true;
}

int PmergeMe::find_small(std::vector<std::pair<int, int> > haystack, int to_find) {
	if (haystack[0].second == to_find)
			return 0;
	for (size_t it = 0; it < haystack.size(); it++) {
		if (haystack[it].second == to_find)
			return static_cast<int>(it);
	}
	return -1;
}

