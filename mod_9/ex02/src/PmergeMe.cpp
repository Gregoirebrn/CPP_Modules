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
		if (!std::isdigit(str[i]) || std::atol(&str[i]) > std::numeric_limits<int>::max())
			throw BadArgument();
	}
}

size_t PmergeMe::jacobsthal(int idx) {
	return (static_cast<std::size_t>(std::pow(2, idx + 1)) + static_cast<std::size_t>(std::pow(-1, idx))) / 3;
}

PmergeMe::PmergeMe(char **av) : _nbr_pair(0), _n(2){
	for (int n = 0; av[n]; n++) {
		check_str(av[n]);
		_vec.push_back(std::atoi(av[n]));
	}
	size_t pt_sz = _vec.size();
	std::cout << "Before : ";
	vec_print(_vec);
	clock_t start = clock();
	vec_algo();
	clock_t end = clock();
	clock_t elapsed = end-start;
	std::cout << "After :  ";
	if (!vec_sort(_vec_final)) {
		_vec = _vec_final;
		vec_merge_insert_jac();
	}
	vec_print(_vec_final);
	double vec_sec = static_cast<double>(elapsed) / CLOCKS_PER_SEC * 100;
	for (int n = 0; av[n]; n++) {
		check_str(av[n]);
		_deq.push_back(std::atoi(av[n]));
	}
	start = clock();
	deq_algo();
	end = clock();
	elapsed = end-start;
	double deq_sec = static_cast<double>(elapsed) / CLOCKS_PER_SEC * 100;
	std::cout << "Time to process a range of " << pt_sz << " elements with std::vector : " << vec_sec << " us" << std::endl;
	std::cout << "Time to process a range of " << pt_sz << " elements with std::deque  : " << deq_sec << " us" << std::endl;
}

void PmergeMe::deq_algo() {
	_size = _deq.size();
	if (_size == 1)
		return (_deq_final = _deq, (void)0);
	if (_size <= 7)
		return (deq_merge_insert_jac());
	if (_size % 2 != 0)
		_size--;
	_nbr_pair = _size / 2;
	deq_first_merge();
	deq_merge();
	deq_insert_jacobsthal();
}

void PmergeMe::deq_first_merge() {
	std::deque<int> bis;
	for (size_t i = 0; i < _size ; i += 2)
	{
		if (_deq[i] >= _deq[i + 1]) {
			bis.push_back(_deq[i]);
			bis.push_back(_deq[i + 1]);
		} else {
			bis.push_back(_deq[i + 1]);
			bis.push_back(_deq[i]);
		}
	}
	_deq = bis;
}

void PmergeMe::deq_merge() {
	std::deque<int> bis;
	_nbr_pair /= 2;
	for (size_t i = 0; i < _nbr_pair ; i += _size / _nbr_pair * 2)
	{
		size_t go_to = i + _size / _nbr_pair;
		if (go_to > _size)
			break ;
		if (_deq[i] <= _deq[go_to])
			deq_in_if(go_to, i, bis);
		else
			deq_in_else(go_to, i, bis);
	}
	_deq = bis;
	if (_nbr_pair != 1)
		deq_merge();
	_nbr_pair *= 2;
	std::deque<int> tmp;
	for (size_t i = 0; i < _size ; i += _size / _nbr_pair * 2) {
		size_t go_to = i + _size / _nbr_pair;
		if (go_to > _size)
			break;
		if (_deq[i] >= _deq[go_to])
			deq_in_if(go_to, i, tmp);
		else
			deq_in_else(go_to, i, tmp);
	}
	_deq = tmp;
}

void PmergeMe::deq_in_if(size_t go_to, size_t i, std::deque<int> &bis) {
	for ( size_t to = go_to ; to < _size && to < go_to + i + _size / _nbr_pair ; to++ )
		bis.push_back(_deq[to]);
	for ( size_t to = i ; to < go_to ; to++ )
		bis.push_back(_deq[to]);
}

void PmergeMe::deq_in_else(size_t go_to, size_t i, std::deque<int> &bis) {
	for ( size_t to = i ; to < _size && to < go_to; to++ )
		bis.push_back(_deq[to]);
	for ( size_t to = go_to ; to < _size && to < go_to + i + _size / _nbr_pair ; to++ )
		bis.push_back(_deq[to]);
}

void PmergeMe::deq_insert_jacobsthal() {
	_deq_final.push_back(_deq[1]);
	_deq_final.push_back(_deq[0]);
	for (size_t j_nbr = 0; _deq_final.size() < _size; _n++) {
		j_nbr = jacobsthal(_n);
		if (j_nbr > _size)
			j_nbr = _size;
		for (size_t last_j_nbr = jacobsthal(_n - 1); j_nbr > last_j_nbr; --j_nbr) {
			for (size_t i = _deq_final.size(); i > 0; i--) {
				if (_deq[j_nbr] > _deq_final[i - 1]) {
					_deq_final.insert( deq_find_iter(i) , _deq[j_nbr]);
					break;
				}
			}
		}
	}
}

std::deque<int>::iterator PmergeMe::deq_find_iter(size_t i) {
	size_t find = 0;
	for (std::deque<int>::iterator it = _deq_final.begin(); it != _deq_final.end(); it++) {
		if (find == i)
			return it;
		find++;
	}
	std::deque<int>::iterator it = _deq_final.end();
	return it;
}

bool PmergeMe::deq_sort(std::deque<int> input) {
	for (size_t i = 0; i < input.size() - 1; i++) {
		if (input[i] > input[i + 1])
			return false;
	}
	return true;
}


void PmergeMe::deq_print(std::deque<int> D) {
	for (std::deque<int>::iterator it=D.begin(); it!=D.end(); ++it)
		std::cout << *it << " " ;
	std::cout << std::endl;
}

void PmergeMe::deq_merge_insert_jac() {
	for (int i = 0; i < (int)_deq.size() - 1; i++) {
		if (_deq[i] > _deq[i + 1]) {
			switch_deq(i);
			i = -1;
		}
	}
	_deq_final = _deq;
}

void PmergeMe::switch_deq(int i) {
	int tmp = _deq[i];
	_deq[i] = _deq[i + 1];
	_deq[i + 1] = tmp;
}

void PmergeMe::vec_algo() {
	_size = _vec.size();
	if (_size == 1)
		return (_vec_final = _vec, (void)0);
	if (_size <= 7)
		return (vec_merge_insert_jac());
	if (_size % 2 != 0)
		_size--;
	_nbr_pair = _size / 2;
	vec_first_merge();
	vec_merge();
	vec_insert_jacobsthal();
}

void PmergeMe::vec_first_merge() {
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
	vec_print(_vec);
}

void PmergeMe::vec_merge() {
	std::vector<int> bis;
	_nbr_pair /= 2;
	for (size_t i = 0; i < _nbr_pair ; i += _size / _nbr_pair * 2)
	{
		size_t go_to = i + _size / _nbr_pair;
		if (go_to > _size)
			break ;
		if (_vec[i] <= _vec[go_to])
			vec_in_if(go_to, i, bis);
		else
			vec_in_else(go_to, i, bis);
	}
	_vec = bis;
	vec_print(_vec);
	if (_nbr_pair != 1)
		vec_merge();
	_nbr_pair *= 2;
	std::vector<int> tmp;
	for (size_t i = 0; i < _size ; i += _size / _nbr_pair * 2) {
		size_t go_to = i + _size / _nbr_pair;
		if (go_to > _size)
			break;
		if (_vec[i] >= _vec[go_to])
			vec_in_if(go_to, i, tmp);
		else
			vec_in_else(go_to, i, tmp);
	}
	_vec = tmp;
}

void PmergeMe::vec_in_if(size_t go_to, size_t i, std::vector<int> &bis) {
	for ( size_t to = go_to ; to < _size && to < go_to + i + _size / _nbr_pair ; to++ )
		bis.push_back(_vec[to]);
	for ( size_t to = i ; to < go_to ; to++ )
		bis.push_back(_vec[to]);
}

void PmergeMe::vec_in_else(size_t go_to, size_t i, std::vector<int> &bis) {
	for ( size_t to = i ; to < _size && to < go_to; to++ )
		bis.push_back(_vec[to]);
	for ( size_t to = go_to ; to < _size && to < go_to + i + _size / _nbr_pair ; to++ )
		bis.push_back(_vec[to]);
}

void PmergeMe::vec_insert_jacobsthal() {
	_vec_final.push_back(_vec[1]);
	_vec_final.push_back(_vec[0]);
	for (size_t j_nbr = 0; _vec_final.size() < _size; _n++) {
		j_nbr = jacobsthal(_n);
		if (j_nbr > _size)
			j_nbr = _size;
		for (size_t last_j_nbr = jacobsthal(_n - 1); j_nbr > last_j_nbr; --j_nbr) {
			for (size_t i = _vec_final.size() ; i > 0; i--) {
				if (_vec[j_nbr] > _vec_final[i - 1]) {
					_vec_final.insert( vec_find_iter(i) , _vec[j_nbr]);
					break;
				}
			}
		}
	}
}

void PmergeMe::vec_merge_insert_jac() {
	for (int i = 0; i < (int)_vec.size() - 1; i++) {
		if (_vec[i] > _vec[i + 1]) {
			switch_vec(i);
			i = -1;
		}
	}
	_vec_final = _vec;
}

void PmergeMe::switch_vec(int i) {
	int tmp = _vec[i];
	_vec[i] = _vec[i + 1];
	_vec[i + 1] = tmp;
}

std::vector<int>::iterator PmergeMe::vec_find_iter(size_t i) {
	size_t find = 0;
	for (std::vector<int>::iterator it = _vec_final.begin(); it != _vec_final.end(); it++) {
		if (find == i)
			return it;
		find++;
	}
	std::vector<int>::iterator it = _vec_final.end();
	return it;
}

bool PmergeMe::vec_sort(std::vector<int> input) {
	for (size_t i = 0; i < input.size() - 1; i++) {
		if (input[i] > input[i + 1])
			return false;
	}
	return true;
}

void PmergeMe::vec_print(std::vector<int> V) {
	for (size_t i=0; i < V.size(); ++i)
		std::cout << V[i] << ", " ;
	std::cout << std::endl;
}

