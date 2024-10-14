/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:58:22 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/12 19:41:32 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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
	std::vector<int>		_jacob;
//	std::deque<int>			_dec;
public:
	~PmergeMe();
	PmergeMe();
	PmergeMe(char **av);
	PmergeMe (const PmergeMe &origin);
	PmergeMe &operator=(const PmergeMe &origin);

	void vec_algo(char **av);
//	void deq_algo(char **av);

	int jacobsthal(int n);
	void print_pair_vec(std::vector<std::pair< int , int > > V);
	void fill_vec();
	void print_vec();
	void print_all(std::vector<int> J);
//	std::vector<int> fordJohnsonSortRecursive(std::vector<std::pair<int, int> >& pairs);

	void recur(std::vector< std::pair<int,int> > input, int n);
	static bool is_sort(std::vector< std::pair<int,int> > input);
};

#endif
