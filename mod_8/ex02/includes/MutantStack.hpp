/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:27:18 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/29 17:59:20 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack  : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack() {};
	iterator begin() { return this->c.begin(); };
	iterator end() { return this->c.end(); };

	const_iterator begin() const { return this->c.begin(); };
	const_iterator end() const { return this->c.end(); };
};

#endif
