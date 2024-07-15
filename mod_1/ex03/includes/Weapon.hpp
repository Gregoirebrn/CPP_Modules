/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:50:14 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/13 12:22:25 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon{
private:
	std::string _type;
public:
	Weapon(std::string weap);
	~Weapon();
	const std::string	getType(void);
	void				setType(std::string new_type);
};

#endif