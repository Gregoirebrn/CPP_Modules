/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:08:30 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 18:34:28 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>


class Base {
public:
	virtual ~Base();

	static Base * generate();
	static void identify(Base* p);
	static void identify(Base& p);

	class CastBad : public std::exception {
	public:
		const char* what() const throw();
	};
};

class A : public Base{
};

class B : public Base{
};

class C : public Base{
};

#endif
