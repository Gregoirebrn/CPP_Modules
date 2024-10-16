/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:31:00 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 12:59:47 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

static void	check_grade(int grade) {
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Form::Form(const std::string &name, int sg, int eg) : _name(name), _s_grade(sg), _e_grade(eg) {
	std::cout << "Form second constructor called" << std::endl;
	check_grade(_s_grade);
	check_grade(_e_grade);
	this->_signed = false;
}

Form::~Form() {
	std::cout << "Form default destructor called" << std::endl;
}

Form::Form(const Form &origin) : _name(origin._name) , _s_grade(origin._s_grade), _e_grade(origin._e_grade) {
	std::cout << "Copy constructor operator called" << std::endl;
	_signed = origin._signed;
}

Form &Form::operator=(const Form &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origin)
		this->_signed = origin._signed;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const Form &c) {
	if (c.getSigned())
		out << "Name of form is " << c.getName() << "." << std::endl << "The Form is signed." << std::endl << "The grade required to execute is " << c.getEGrade() << "." << std::endl << "And the grade required to sign is " << c.getSGrade() << ".";
	else
		out << "Name of form is " << c.getName() << "." << std::endl << "The Form is not signed." << std::endl << "The grade required to execute is " << c.getEGrade() << "." << std::endl << "And the grade required to sign is " << c.getSGrade() << ".";
	return out;
}

std::string Form::getName() const {
	return this->_name;
}

int Form::getEGrade() const {
	return (this->_e_grade);
}

int Form::getSGrade() const {
	return (this->_s_grade);
}

int Form::getSigned() const {
	return (this->_signed);
}

void Form::beSigned(const Bureaucrat &signer) {
	if (signer.getGrade() > this->_s_grade)
		throw (Form::GradeTooLowException());
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("The grade is Too High.");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("The grade is Too Low.");
}

