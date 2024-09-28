/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:46:38 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/28 16:24:29 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void Span::addNumber(int number) {
	_added++;
	if (_added > _n)
		throw Span::OutOfBond() ;
	_vec.push_back(number);
}

int Span::longestSpan() {
	if (_added < 2)
		throw Span::NoRange();
	std::sort (_vec.begin(), _vec.end());
	return *(_vec.end() -1) - *_vec.begin();
}

int Span::shortestSpan() {
	if (_added < 2)
		throw Span::NoRange();
	std::sort (_vec.begin(), _vec.end());
	int shortest = *(_vec.begin() + 1) - *_vec.begin();
	for (size_t it=0; _vec[it] != *(_vec.end() - 1); ++it) {
		if (shortest > _vec[it + 1] - _vec[it])
			shortest = _vec[it + 1] - _vec[it];
	}
	return shortest;
}

void Span::OneCall(std::vector<int> range) {
	if (range.size() < _n - _added) {
		_vec.insert(_vec.end(), range.begin(), range.end());
		_added += range.size();
	}
	else {
		int end_to = static_cast<int>(_n - _added);
		_vec.insert(_vec.end(), range.begin(), (range.begin() + (end_to)));
		_added += range.size();
	}
}

std::vector<int> Span::GetVec() const {
	return _vec;
}

void Span::print_vec(){
	int i = 0;
	std::cout << "Vector of " << _added << " elements :" << std::endl;
	for (std::vector<int>::iterator it=_vec.begin(); it!=_vec.end(); ++it) {
		std::cout << "[" << i << "] = " << *it << std::endl;
		i++;
	}
}

Span::Span(Span const &copy){
	_n = copy.GetN();
	std::vector<int> cop_vec = copy.GetVec();
	_vec.insert(_vec.end(), cop_vec.begin(), cop_vec.end());
	_added = copy.GetAdded();
}

Span &Span::operator=(Span rhs) {
	if (this != &rhs) {
		_n = rhs._n;
		std::vector<int> cop_vec = rhs.GetVec();
		_vec.insert(_vec.end(), cop_vec.begin(), cop_vec.end());
		_added = GetAdded();
	}
	return *this;
}

size_t Span::GetN() const {
	return _n;
}

size_t Span::GetAdded() const {
	return _added;
}
