/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:45:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 14:54:34 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(const Intern &origin) {
	(void)origin;
}

Intern &Intern::operator=(const Intern &origin) {
	(void)origin;
	return *this;
}

static int hash_level(std::string level) {
	unsigned int hash = 0;
	for (unsigned int i = 0; level[i]; i++){
		hash = hash * 43 + level[i];
	}
	return (hash);
}

AForm *Intern::makeForm(std::string name_form, std::string target_of_form) {
	switch (hash_level(name_form))
	{
		case 1231330906: {
			std::cout << "Intern creates a " << name_form << " form and his name is " << target_of_form << " !" << std::endl;
			return (new PresidentialPardonForm(target_of_form));
		}
		case 471008488: {
			std::cout << "Intern creates a " << name_form << " form and his name is " << target_of_form << " !" << std::endl;
			return (new RobotomyRequestForm(target_of_form));
		}
		case 1032646283: {
			std::cout << "Intern creates a " << name_form << " form and his name is " << target_of_form << " !" << std::endl;
			return (new ShrubberyCreationForm(target_of_form));
		}
		default:
			throw NotAForm();
	}
}

const char *Intern::NotAForm::what() const throw() {
	return ("The form name passed as parameter doesn’t exist.");
}
