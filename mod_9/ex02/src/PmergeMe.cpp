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
		std::cout << *it << ", " ;
		i++;
	}
}

void PmergeMe::print_all(std::vector<int> J) {
	int i = 0;
	std::cout << "RESULT of " << J.size() << " elements :" << std::endl;
	for (std::vector<int>::iterator it=J.begin(); it!=J.end(); ++it) {
		std::cout << *it << ", " ;
		i++;
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(char **av) : _nbr_pair(0), _n(2){
	vec_algo(av);
//	deque(av);
}

void PmergeMe::vec_algo(char **av) {
	for (int n = 0; av[n]; n++) {
		check_str(av[n]);
		_vec.push_back(std::atoi(av[n]));
	}
	_size = _vec.size();
	if (_size % 2 != 0)
		_size--;
	_nbr_pair = _size / 2;
	first_merge();
	ford_johnson();
	insert_jacobsthal();
}

void PmergeMe::merge() {
	std::vector<int> bis;
	for (size_t i = 0; i < _nbr_pair ; i += _size / _nbr_pair * 2)
	{
		size_t go_to = i + _size / _nbr_pair;
		if (go_to > _size)
			break ;
		if (_vec[i] <= _vec[go_to]) {
			for ( size_t to = go_to ; to < _size && to < go_to + i + _size / _nbr_pair ; to++ ) {
				bis.push_back(_vec[to]);
			}
			for ( size_t to = i ; to < go_to ; to++ ) {
				bis.push_back(_vec[to]);
			}
		} else {
			for ( size_t to = i ; to < _size && to < go_to; to++ ) {
				bis.push_back(_vec[to]);
			}
			for ( size_t to = go_to ; to < _size && to < go_to + i + _size / _nbr_pair ; to++ ) {
				bis.push_back(_vec[to]);
			}
		}
	}
	print_all(bis);
	_vec = bis;
	print_all(_vec);
	std::cout << "nbr_pair = " << _nbr_pair << std::endl;
}

void PmergeMe::insert() {
	std::vector<int> bis;
	for (size_t i = 0; i < _size ; i += _size / _nbr_pair * 2)
	{
		size_t go_to = i + _size / _nbr_pair;
		if (go_to > _size)
			break ;
		if (_vec[i] >= _vec[go_to]) {
			for ( size_t to = go_to ; to < _size && to < go_to + i + _size / _nbr_pair ; to++ ) {
				bis.push_back(_vec[to]);
			}
			for ( size_t to = i ; to < go_to ; to++ ) {
				bis.push_back(_vec[to]);
			}
		} else {
			for ( size_t to = i ; to < _size && to < go_to; to++ ) {
				bis.push_back(_vec[to]);
			}
			for ( size_t to = go_to ; to < _size && to < go_to + i + _size / _nbr_pair ; to++ ) {
				bis.push_back(_vec[to]);
			}
		}
	}
	std::cout << "GGGGGGGGGGG" << std::endl;
	print_all(_vec);
	_vec = bis;
	print_all(_vec);
	std::cout << "GGGGGGGGGGG" << std::endl;
	_nbr_pair *= 2;
	std::cout << "nbr_pair = " << _nbr_pair << std::endl;
}

void	PmergeMe::ford_johnson() {
	_nbr_pair /= 2;
	merge();
	if (_nbr_pair != 1)
		ford_johnson();
	insert();
}

void PmergeMe::first_merge() {
	std::vector<int> bis;
	for (size_t i = 0; i < _size ; i += 2)
	{
		if (_vec[i] >= _vec[i + 1]) {
			bis.push_back(_vec[i]);
			bis.push_back(_vec[i + 1]);
		} else {
			bis.push_back(_vec[i + 1]);
			bis.push_back(_vec[i]);
		}
	}
	_vec = bis;
}

size_t PmergeMe::jacobsthal(int idx) {
	return (static_cast<std::size_t>(std::pow(2, idx + 1)) + static_cast<std::size_t>(std::pow(-1, idx))) / 3;
}

void PmergeMe::insert_jacobsthal() {
	_final.push_back(_vec[1]);
	_final.push_back(_vec[0]);
	for (size_t j_nbr = 0; _final.size() < _size; _n++) {
		j_nbr = jacobsthal(_n);
		if (j_nbr > _size)
			j_nbr = _size;
		for (size_t last_j_nbr = jacobsthal(_n - 1); j_nbr > last_j_nbr; --j_nbr) {
			for (size_t i = _final.size(); i > 0; i--) {
				if (_vec[j_nbr] > _final[i - 1]) {
					_final.insert( find_iter(i) , _vec[j_nbr]);
					break;
				}
			}
		}
	}
		print_all(_final);
}

std::vector<int>::iterator PmergeMe::find_iter(size_t i) {
	size_t find = 0;
	for (std::vector<int>::iterator it = _final.begin(); it != _final.end(); it++) {
		if (find == i)
			return it;
		find++;
	}
	std::vector<int>::iterator it = _final.end();
	return it;
}

