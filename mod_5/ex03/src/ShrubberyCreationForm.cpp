/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:45:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/09 18:23:58 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 147, 137), _target("default") {
	std::cout << "ShrubberyCreationForm second constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 147, 137) , _target(target) {
	std::cout << "ShrubberyCreationForm second constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &origin) : AForm(origin), _target(origin._target) {
	std::cout << "Copy constructor operator called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origine) {
		this->AForm::operator=(origine);
		_target = origine._target;
	}
	return (*this);
}

int	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	is_grade_exe(executor);
	std::ofstream outfile;
	outfile.open((_target + "_shrubbery").c_str());
	outfile << "       _-_\n"
			<< "    /~~   ~~\\\n"
			<< " /~~         ~~\\\n"
			<< "{               }\n"
			<< " \\  _-     -_  /\n"
			<< "   ~  \\\\ //  ~\n"
			<< "_- -   | | _- _\n"
			<< "  _ -  | |   -_\n"
			<< "      // \\\\" << std::endl;
	outfile.close();
	return (0);
}

