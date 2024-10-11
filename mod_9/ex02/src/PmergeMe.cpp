/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:57:57 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/11 18:22:46 by grebrune         ###   ########.fr       */
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

void	PmergeMe::print_pair_vec() {
	int i = 0;
	std::pair< int , int > pair;
	std::cout << "PAIR of " << _pair.size() << " elements :" << std::endl;
	for (std::vector<std::pair< int , int > >::iterator it=_pair.begin(); it!=_pair.end(); ++it) {
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
	std::vector<int> sortedResult = fordJohnsonSortRecursive(_pair);
	print_all(sortedResult);
}

std::vector<int> PmergeMe::jacobsthal(int n) {
	std::vector<int> J(n);
//	std::pair<int , int > pair_of_vec = *_pair.begin();
//	J[0] = pair_of_vec.second;
	if (n > 1) {
		J[1] = 1;
		for (int i = 2; i < n; ++i) {
			J[i] = J[i - 2] + 2 * J[i - 1];
		}
	}
//	print_all(J);
	return J;
}

void PmergeMe::vec_algo(char **av) {
	int n = 0;
	for (n = 0; av[n]; n++) {
		check_str(av[n]);
		_vec.push_back(std::atoi(av[n]));
	}
	fill_vec();
	jacobsthal(n);
}

void PmergeMe::print_all(std::vector<int> J) {
	int i = 0;
	std::cout << "RESULT of " << J.size() << " elements :" << std::endl;
	for (std::vector<int>::iterator it=J.begin(); it!=J.end(); ++it) {
		std::cout << "[" << i << "] = " << *it << std::endl;
		i++;
	}
}

std::vector<int> mergeSortedPairs(const std::vector<std::pair<int, int> >& left,
								  const std::vector<std::pair<int, int> >& right) {
	std::vector<int> result;
	size_t i = 0, j = 0;

	// Merge the two sorted pairs (left and right) into one sorted vector
	while (i < left.size() && j < right.size()) {
		if (left[i].second <= right[j].first) {
			result.push_back(left[i].first);
			result.push_back(left[i].second);
			i++;
		} else {
			result.push_back(right[j].first);
			result.push_back(right[j].second);
			j++;
		}
	}

	// Add remaining elements if there are any
	while (i < left.size()) {
		result.push_back(left[i].first);
		result.push_back(left[i].second);
		i++;
	}

	while (j < right.size()) {
		result.push_back(right[j].first);
		result.push_back(right[j].second);
		j++;
	}

	return result;
}

// Recursive function implementing Ford-Johnson algorithm
std::vector<int> PmergeMe::fordJohnsonSortRecursive(std::vector<std::pair<int, int> >& pairs) {
	// Base case: If we have one or no pairs, return the result
	if (pairs.size() == 1) {
		std::vector<int> sorted;
		sorted.push_back(pairs[0].first);
		sorted.push_back(pairs[0].second);
		return sorted;
	}

	// Split the vector of pairs into two halves
	size_t mid = pairs.size() / 2;
	std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
	std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

	// Recursively sort the left and right halves
	std::vector<int> sortedLeft = fordJohnsonSortRecursive(left);
	std::vector<int> sortedRight = fordJohnsonSortRecursive(right);

	// Merge the two sorted halves
	return mergeSortedPairs(left, right);
}



