/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:43:04 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/05 18:55:49 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string &name) : AForm(name, 145, 137), _target(name)
{
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
		*this = origine;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const PresidentialPardonForm &c) {
	out << c.getName() << ", is signed " << c.getSigned() << " required to execute it " << c.getEGrade() << " grade required to sign it " << c.getSGrade() << ".";
	return out;
}