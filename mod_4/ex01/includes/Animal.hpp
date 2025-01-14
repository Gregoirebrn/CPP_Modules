/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:48:16 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/01 13:27:30 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
private:
	std::string		_type;
public:
	Animal();
	Animal(std::string name);
	virtual ~Animal();
	Animal (const Animal &);
	Animal &operator=(const Animal &origin);

	std::string getType() const ;
	virtual void makeSound() const;
};

#endif
