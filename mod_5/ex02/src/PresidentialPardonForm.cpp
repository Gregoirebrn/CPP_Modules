/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:43:04 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/09 18:40:22 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {
	std::cout << "PresidentialPardonForm second constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5) , _target(target) {
	std::cout << "PresidentialPardonForm second constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm default destructor called" << std::endl; }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &origin) : AForm(origin), _target(origin._target) {
	std::cout << "Copy constructor operator called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origine)
	{
		this->AForm::operator=(origine);
		_target = origine._target;
	}
	return (*this);
}

int PresidentialPardonForm::execute(ScalarConverter const & executor) const {
	is_grade_exe(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return (0);
}