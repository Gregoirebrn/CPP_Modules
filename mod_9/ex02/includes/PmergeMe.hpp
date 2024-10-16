/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:58:22 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/14 15:51:17 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <limits>
#include <ctime>
#include <complex>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
#include "BadArgument.hpp"

class PmergeMe {
	std::vector<int>		_vec;
	std::vector<int>		_vec_final;
	std::deque<int>			_deq;
	std::deque<int>			_deq_final;
	size_t					_nbr_pair;
	size_t					_size;
	int						_n;
public:
	~PmergeMe();
	PmergeMe();
	PmergeMe(char **av);
	PmergeMe (const PmergeMe &origin);
	PmergeMe &operator=(const PmergeMe &origin);

	size_t jacobsthal(int n);


	void deq_algo();

	void deq_insert_jacobsthal();
	void deq_in_if(size_t go_to, size_t i, std::deque<int> bis);
	void deq_in_else(size_t go_to, size_t i, std::deque<int> bis);
	void deq_merge();
	void deq_first_merge();
	std::deque<int>::iterator deq_find_iter(size_t i);
	bool deq_sort(std::deque<int> input);
	void vec_print(std::vector<int> V);


	void vec_algo();

	void vec_insert_jacobsthal();
	void vec_in_if(size_t go_to, size_t i, std::vector<int> bis);
	void vec_in_else(size_t go_to, size_t i, std::vector<int> bis);
	void vec_merge();
	void vec_first_merge();
	std::vector<int>::iterator vec_find_iter(size_t i);
	bool vec_sort(std::vector<int> input);
	void deq_print(std::deque<int> D);

};

#endif
