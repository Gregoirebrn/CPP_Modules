/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:50:14 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/15 15:43:02 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
private:
	std::string _type;
public:
	Weapon(std::string weap);
	~Weapon();
	const std::string& getType(void) const;
	void setType(std::string new_type);
};

#endif