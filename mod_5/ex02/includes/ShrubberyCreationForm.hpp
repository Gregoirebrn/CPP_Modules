/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:35:40 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 17:01:12 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string	_target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm() {}
	ShrubberyCreationForm (const ShrubberyCreationForm &origin);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &origin);

	int	execute(Bureaucrat const & executor) const;

	class CanNotOpenFile : public std::exception {
	public:
		const char* what() const throw();
	};
};

#endif