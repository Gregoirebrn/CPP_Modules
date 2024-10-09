/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:40:01 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/09 17:53:41 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
}

void printstack(std::stack<int> s)
{
	if (s.empty())
		return;
	int x = s.top();
	s.pop();
	printstack(s);
	std::cout << x << std::endl;
	s.push(x);
}

void RPN::check_num_arg(std::string arg) {
	size_t count_nbr = 0;
	size_t count_ope = 0;
	for (int i = 0; arg[i] ; i++) {
		if ((!isdigit(arg[i]) &&
			 (arg[i] != '+' && arg[i] != '-' && arg[i] != '*' &&
			  arg[i] != '/' && arg[i] != ' ')) ||
			(isdigit(arg[i]) && arg[i + 1] && isdigit(arg[i + 1])))
			throw BadArgument();
		if (isdigit(arg[i]))
			count_nbr++;
		if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/')
			count_ope++;
	}
	if (count_nbr - 1 != count_ope)
		throw BadArgument();
}

RPN::RPN(const char *arg) : _nbr_in(0) {
	check_num_arg(arg);
	for (int i = 0; arg[i] ; i++) {
		if (isdigit(arg[i])) {
			_nbr_in++;
			_stack.push(arg[i] - 48);
		}
		if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/') {
			find_operator(arg[i]);
		}
	}
	std::cout << _stack.top() << std::endl;
}

int RPN::find_operator(char c) {
	if (_nbr_in < 2)
		return 0;
	int num1 = _stack.top();
	_stack.pop();
	int num2 = _stack.top();
	_stack.pop();
	_nbr_in -= 2;
	switch (static_cast<int>(c))
	{
		case 42 : {
			int res = num1 * num2;
			_nbr_in++;
			_stack.push(res);
			return 0;
		}
		case 43 : {
			int res = num2 + num1;
			_nbr_in++;
			_stack.push(res);
			return 0;
		}
		case 45 : {
			int res = num2 - num1;
			_nbr_in++;
			_stack.push(res);
			return 0;
		}
		case 47: {
			int res = num2 / num1;
			_nbr_in++;
			_stack.push(res);
			return 0;
		}
		default:
			return -1;
	}
}

RPN::RPN(const RPN &origin) {
	if (this != &origin) {
		_rpn = origin._rpn;
		_stack = origin._stack;
		_nbr_in = origin._nbr_in;
	}
}

RPN &RPN::operator=(const RPN &origin) {
	if (this != &origin) {
		_rpn = origin._rpn;
		_stack = origin._stack;
		_nbr_in = origin._nbr_in;
	}
	return *this;
}

