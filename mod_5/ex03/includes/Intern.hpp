/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:33:17 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 17:06:43 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {
public:
	Intern() {}
	~Intern() {}
	Intern (const Intern &origin);
	Intern &operator=(const Intern &origin);

	AForm *makeForm(std::string name_form, std::string target_of_form);

	class NotAForm : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Intern &c);

#endif