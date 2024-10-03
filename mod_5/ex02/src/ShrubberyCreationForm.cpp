/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:45:12 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 14:40:00 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "../../ex03/includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137) , _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &origin) : AForm(origin), _target(origin._target) {
	std::cout << "Copy constructor operator called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origin) {
		this->AForm::operator=(origin);
		_target = origin._target;
	}
	return (*this);
}

int	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	is_grade_exe(executor);
	std::ofstream outfile;
	outfile.open((_target + "_shrubbery").c_str());
	if (outfile.is_open()) {
	outfile << "       _-_\n"
			<< "    /~~   ~~\\\n"
			<< " /~~         ~~\\\n"
			<< "{               }\n"
			<< " \\  _-     -_  /\n"
			<< "   ~  \\\\ //  ~\n"
			<< "_- -   | | _- _\n"
			<< "  _ -  | |   -_\n"
			<< "      // \\\\" << std::endl
			<< "       _-_\n"
			<< "    /~~   ~~\\\n"
			<< " /~~         ~~\\\n"
			<< "{               }\n"
			<< " \\  _-     -_  /\n"
			<< "   ~  \\\\ //  ~\n"
			<< "_- -   | | _- _\n"
			<< "  _ -  | |   -_\n"
			<< "      // \\\\" << std::endl;
	outfile.close();
	}
	else
		throw ShrubberyCreationForm::CanNotOpenFile();
	std::cout << "Created a file " << _target + "_shrubbery" << " in the working directory, and writed ASCII trees inside it." << std::endl;
	return (0);
}

const char *ShrubberyCreationForm::CanNotOpenFile::what() const throw()
{
	return ("Can not open file");
}
