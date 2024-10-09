/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:38:40 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/09 17:52:17 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include "BadArgument.hpp"

class RPN {
	std::stack<int>		_stack;
	std::string			_rpn;
	size_t				_nbr_in;
	RPN();
	RPN (const RPN &origin);
	RPN &operator=(const RPN &origin);
public:
	RPN (const char *rpn);
	~RPN() {}
	int find_operator(char c);
	void check_num_arg(std::string arg);
};

#endif
