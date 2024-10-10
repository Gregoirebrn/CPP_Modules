/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:38:40 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/10 13:55:42 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include "BadArgument.hpp"

class RPN {
	std::stack<int>		_stack;
	size_t				_nbr_in;
	RPN();
	RPN (const RPN &origin);
	RPN &operator=(const RPN &origin);
public:
	~RPN();
	RPN (const char *rpn);
	int find_operator(char c);
	static void check_num_arg(std::string arg);
};

#endif
