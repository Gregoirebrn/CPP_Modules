/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:58:22 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/10 18:59:04 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include "BadArgument.hpp"

class PmergeMe {
	std::pair< std::vector<int>, std::vector<int> >		_pair;
	std::vector<int>		_vec;
	std::vector<int>		_big;
	std::vector<int>		_small;
//	std::deque<int>			_dec;
public:
	~PmergeMe();
	PmergeMe();
	PmergeMe(char **av);
	PmergeMe (const PmergeMe &origin);
	PmergeMe &operator=(const PmergeMe &origin);

	void vec_algo(char **av);
//	void deq_algo(char **av);


	void fill_vec();
	void print_vec();
	void print_all();
void jacobsthal();
};

#endif
