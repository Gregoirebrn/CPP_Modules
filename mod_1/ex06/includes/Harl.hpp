/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:21:01 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/29 17:18:03 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl{
private:
	;
public:
	Harl();
	~Harl();
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void switcher(std::string level);
	int  hash_level(std::string level);
};

#endif