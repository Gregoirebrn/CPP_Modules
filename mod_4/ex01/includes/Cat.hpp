/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:54:22 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/01 13:59:33 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal{
private:
	Brain *brain;
	std::string		_type;
public:
	Cat();
	~Cat();
	Cat (const Cat &);
	Cat &operator=(const Cat &origine);
};

#endif