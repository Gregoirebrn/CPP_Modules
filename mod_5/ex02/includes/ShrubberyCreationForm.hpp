/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:35:40 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/05 18:40:21 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string	_target;
public:
	ShrubberyCreationForm(const std::string &name);
	~ShrubberyCreationForm();
	ShrubberyCreationForm (const ShrubberyCreationForm &origine);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &origine);

	void	execute(const ShrubberyCreationForm &base) const ;
};

#endif