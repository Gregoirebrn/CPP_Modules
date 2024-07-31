/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:43:16 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/31 11:16:19 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"

class DiamondTrap : public ClapTrap{
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();

	DiamondTrap (const DiamondTrap &);
	DiamondTrap &operator=(const DiamondTrap &fix);

	void attack(const std::string& target);
	void highFivesGuys(void);
	void whoAmI();
};

#endif
