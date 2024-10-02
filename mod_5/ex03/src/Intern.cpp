/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:45:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/02 14:12:26 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){
	std::cout << "Interm default constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Interm default destructor called" << std::endl;
}

Intern::Intern(const Intern &origine) {
	(void)origine;
}

Intern &Intern::operator=(const Intern &origine) {
	(void)origine;
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
			std::cout << "Intern creates " << target_of_form << " !" << std::endl;
			return (new PresidentialPardonForm(target_of_form));
		}
		case 471008488: {
			std::cout << "Intern creates " << target_of_form << " !" << std::endl;
			return (new RobotomyRequestForm(target_of_form));
		}
		case 1032646283: {
			std::cout << "Intern creates " << target_of_form << " !" << std::endl;
			return (new ShrubberyCreationForm(target_of_form));
		}
		default:
			throw NotAForm();
	}
	AForm *fill = NULL;
	return (fill);
}

const char *Intern::NotAForm::what() const throw() {
	return ("The form name passed as parameter doesn’t exist.");
}
