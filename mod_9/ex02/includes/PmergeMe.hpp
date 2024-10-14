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

#include <cstdlib>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
#include "BadArgument.hpp"

class PmergeMe {
	std::vector< std::pair<int,int> >		_pair;
	std::vector<int>		_vec;
	std::vector<int>		_final;
	int						_jacob_number;
//	std::deque<int>			_dec;
public:
	~PmergeMe();
	PmergeMe();
	PmergeMe(char **av);
	PmergeMe (const PmergeMe &origin);
	PmergeMe &operator=(const PmergeMe &origin);

	void vec_algo(char **av);
//	void deq_algo(char **av);

	size_t jacobsthal(int n);
	void print_pair_vec(std::vector<std::pair< int , int > > V);
	void fill_vec();
	void print_vec();
	void print_all(std::vector<int> J);
//	std::vector<int> fordJohnsonSortRecursive(std::vector<std::pair<int, int> >& pairs);

	void recur(std::vector< std::pair<int,int> > input);
	static bool is_sort(std::vector< std::pair<int,int> > input);
	int find_small(std::vector<std::pair<int, int> > haystack, int to_find);
	std::vector<std::pair< int , int > >::iterator find_iter(std::vector<std::pair< int , int > > V, int i);
};

#endif
