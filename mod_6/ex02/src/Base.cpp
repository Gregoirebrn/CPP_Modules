/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:49:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/17 18:49:12 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {
	std::cout << "Base default destructor called" << std::endl;
}

Base *Base::generate() {
	switch (std::rand()% 3 % 6)
	{
		case 1 : {
		A *a_class = new A();
		std::cout << "Make A class!" << std::endl;
		return a_class;
		}
		case 2 : {
		B *a_class = new B();
		std::cout << "Make B class!" << std::endl;
		return a_class;
		}
		case 3 : {
		C *a_class = new C();
		std::cout << "Make C class!" << std::endl;
		return a_class;
		}
		default:
			return NULL;
	}
}

void Base::identify(Base *p)
{
	A* a = dynamic_cast<A *> (p);
	if (!a)
		std::cout << "Not A class!" << std::endl;
	else
		return (std::cout << "Its A class!" << std::endl, (void)0);
	B* b = dynamic_cast<B *> (p);
	if (!b)
		std::cout << "Not B class!" << std::endl;
	else
		return (std::cout << "Its B class!" << std::endl, (void)0);
	C* c = dynamic_cast<C *> (p);
	if (!c)
		std::cout << "Not C class!" << std::endl;
	else
		return (std::cout << "Its C class!" << std::endl, (void)0);
}

void Base::identify(Base &p) {
	try {
		A &z = dynamic_cast<A &> (p);
		std::cout << "Conversion to A class all good!" << std::endl;
		(void)z;
	}
	catch (std::exception &cb) {
		std::cout << "It's not a A class" << cb.what() << std::endl;
		try {
			B &z = dynamic_cast<B &> (p);
			std::cout << "Conversion to B class all good!" << std::endl;
		(void)z;
		}
		catch (std::exception &cb) {
			std::cout << "It's not a B class" << cb.what() << std::endl;
			try {
				C &z = dynamic_cast<C &> (p);
				(void)z;
				std::cout << "Conversion to C class all good!" << std::endl;
			}
			catch (std::exception &cb) {
				std::cout << "It's not a C class" << cb.what() << std::endl;
				std::cout << "Maybe a reference to another class !" << std::endl;
			}
		}
	}
}

const char *Base::CastBad::what() const throw()
{
	return ("DownCast gone wrong!");
}
