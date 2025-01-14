/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:54:25 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/31 15:13:52 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal{
private:
	std::string		_type;
public:
	Dog();
	~Dog();
	Dog (const Dog &);
	Dog &operator=(const Dog &origin);
	void makeSound() const;
};

#endif