/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:00:54 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/09 19:30:19 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
private:
	std::string _name;
public:
	void	annonce(void);
	Zombie	(std::string name);
	~Zombie();
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif