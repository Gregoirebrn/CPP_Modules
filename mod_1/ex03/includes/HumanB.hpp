/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:54:13 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/15 15:52:13 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB{
private:
	Weapon* _weapon;
	std::string _name;
public:
	HumanB(std::string name);
	~HumanB();
	void attack() const;
	void setWeapon(Weapon& new_weapon);
};

#endif