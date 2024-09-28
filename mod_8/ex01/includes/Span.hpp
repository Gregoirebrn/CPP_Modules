/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:47:21 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/28 16:09:39 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>


class Span {
private:
	std::vector<int>	_vec;
	size_t				_n;
	size_t				_added;
public:
//	Span() : _vec(0), _n(0), _added(0) {} ;
	Span(int n) : _vec(0), _n(n), _added(0) {} ;
	~Span() {};

	void addNumber(int number);
	int shortestSpan();
	int longestSpan();

	std::vector<int> GetVec() const;
	size_t GetN() const ;
	size_t GetAdded() const ;

	void OneCall(std::vector<int> range);
	void print_vec();

	Span(Span const &copy);

	Span & operator = (Span rhs);

	class OutOfBond : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("List is full!");
	}
	};
	class NoRange : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("No range could be find!");
		}
	};
};

#endif
