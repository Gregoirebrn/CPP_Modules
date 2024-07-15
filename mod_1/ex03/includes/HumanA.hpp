/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:56:41 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/15 15:52:13 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>


class HumanA{
private:
	Weapon& _weapon;
	std::string _name;
public:
	HumanA(std::string const name, Weapon& new_weapon);
	~HumanA();
	void attack();
};

#endif