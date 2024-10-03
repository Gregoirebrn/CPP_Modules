/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:34:23 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 17:00:23 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

static void	check_grade(int grade) {
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

AForm::AForm(const std::string &name, int sg, int eg) : _name(name), _s_grade(sg), _e_grade(eg) {
	check_grade(_s_grade);
	check_grade(_e_grade);
	this->_signed = false;
}

AForm::AForm(const AForm &origin) : _name(origin._name) , _signed(origin._signed), _s_grade(origin._s_grade), _e_grade(origin._e_grade) {
	std::cout << "Copy constructor operator called" << std::endl;
}

AForm &AForm::operator=(const AForm &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origin)
		this->_signed = origin._signed;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const AForm &c) {
	if (c.getSigned())
		out << "Name of form is " << c.getName() << "."
			<< std::endl << "The Form is signed."
			<< std::endl << "The grade required to execute is "
			<< c.getEGrade() << "." << std::endl
			<< "And the grade required to sign is " << c.getSGrade() << ".";
	else
		out << "Name of form is " << c.getName()
		<< "." << std::endl << "The Form is not signed."
		<< std::endl << "The grade required to execute is "
		<< c.getEGrade() << "." << std::endl
		<< "And the grade required to sign is " << c.getSGrade() << ".";
	return out;
}

std::string AForm::getName() const {
	return this->_name;
}

int AForm::getEGrade() const {
	return (this->_e_grade);
}

int AForm::getSGrade() const {
	return (this->_s_grade);
}

int AForm::getSigned() const {
	return (this->_signed);
}

void AForm::beSigned(const Bureaucrat &origin) {
	if (origin.getGrade() > this->_s_grade)
		throw (AForm::GradeTooLowException());
	this->_signed = true;
}

void AForm::is_grade_exe(Bureaucrat const & executor) const {
	if (!this->getSigned())
		throw AForm::IsNotSigned();
	if (executor.getGrade() > _e_grade)
		throw AForm::GradeTooLowException() ;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("The grade is Too High.");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("The grade is Too Low.");
}

const char *AForm::IsNotSigned::what() const throw() {
	return ("The Form is not signed.");
}

