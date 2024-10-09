/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotFound.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:52:42 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/08 17:52:42 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTFOUND_HPP
#define NOTFOUND_HPP

#include <exception>

class NotFound : public std::exception {
public:
	virtual const char* what() const throw() {
		return ("No occurrence found!");
	}
};

#endif