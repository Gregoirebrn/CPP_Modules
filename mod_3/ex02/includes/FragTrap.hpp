/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:43:16 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/31 11:08:11 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

	FragTrap (const FragTrap &origine);
	FragTrap &operator=(const FragTrap &fix);

	void attack(const std::string& target);
	void highFivesGuys(void);
};

#endif
