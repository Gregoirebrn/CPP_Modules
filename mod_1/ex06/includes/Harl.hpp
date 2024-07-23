/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:21:01 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/17 17:24:48 by grebrune         ###   ########.fr       */
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
	void complain( std::string level );
	void switcher(std::string level);
};

#endif