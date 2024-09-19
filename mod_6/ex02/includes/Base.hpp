/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:08:30 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/19 12:30:55 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>


class Base {
public:
	Base();
	virtual ~Base();

	static Base * generate(void);
	static void identify(Base* p);
	static void identify(Base& p);
	class CastBad : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

class A : public Base{
};

class B : public Base{
};

class C : public Base{
};

#endif
