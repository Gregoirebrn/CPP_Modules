/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:46:31 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/17 18:46:31 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <bits/stdc++.h>


class Serializer {
private:
	Serializer();
	~Serializer();
public:
	Serializer (const Serializer &origine);
	Serializer &operator=(const Serializer &origine);
};

#endif
