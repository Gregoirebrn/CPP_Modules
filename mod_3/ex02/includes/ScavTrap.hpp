/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:43:16 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/30 17:50:31 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();

	ScavTrap (const ScavTrap &);
	ScavTrap &operator=(const ScavTrap &fix);

	void attack(const std::string& target);
	void guardGate();
};

#endif
