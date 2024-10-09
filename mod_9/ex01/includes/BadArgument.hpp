/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BadArgument.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:02:36 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/09 13:02:36 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BADARGUMENT_HPP
#define BADARGUMENT_HPP

#include <exception>

class BadArgument : public std::exception {
public:
	const char* what() const throw() {
		return ("Bad argument in the given string !");
	}
};

#endif