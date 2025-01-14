/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:48:16 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/01 13:30:23 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
private:
	std::string		_type;
public:
	WrongAnimal();
	WrongAnimal(std::string name);
	virtual ~WrongAnimal();
	WrongAnimal (const WrongAnimal &);
	WrongAnimal &operator=(const WrongAnimal &origin);

	std::string getType() const ;
	void makeSound() const;
};

#endif
