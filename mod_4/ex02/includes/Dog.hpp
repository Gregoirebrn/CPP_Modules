/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:54:25 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/02 12:03:05 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal{
private:
	Brain *brain;
	std::string		_type;
public:
	Dog();
	~Dog();
	Dog (const Dog &);
	Dog &operator=(const Dog &origine);

	virtual void makeSound() const;

};

#endif