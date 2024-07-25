/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:31:10 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/25 18:11:47 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0) , _y(0) {
	std::cout << "Constru" << std::endl;
}

Point::Point(int x, int y) : _x(x), _y(y) {
	std::cout << "Constru int " << std::endl;
}

Point::~Point() {
	std::cout << "Destructor" << std::endl;
}

Point::Point(const Point &) {

}

Point &Point::operator=(const Point &point) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &point)
		return (*this);
		this->_x = _x.getRawBits();
	return (*this);
}
