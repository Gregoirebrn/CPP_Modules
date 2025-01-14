/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:48:16 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/01 13:39:39 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
private:
	std::string		_type;
public:
	WrongCat();
	~WrongCat();
	WrongCat (const WrongCat &);
	WrongCat &operator=(const WrongCat &origin);
};

#endif
