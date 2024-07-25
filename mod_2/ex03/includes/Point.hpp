/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:32:04 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/25 18:10:32 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

class Point{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(int x, int y);
	~Point();
	Point (const Point &);
	Point &operator=(const Point &fix);
};