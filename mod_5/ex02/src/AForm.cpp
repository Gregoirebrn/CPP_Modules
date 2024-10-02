/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:34:23 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/02 16:35:59 by grebrune         ###   ########.fr       */
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
//	std::cout << "Form second constructor called" << std::endl;
	check_grade(_s_grade);
	check_grade(_e_grade);
	this->_signed = false;
}

AForm::AForm() : _name("default"), _signed(false), _s_grade(0), _e_grade(0) {
	std::cout << "AForm default destructor called" << std::endl;
}

AForm::~AForm() {
//	std::cout << "AForm default destructor called" << std::endl;
}

AForm::AForm(const AForm &origine) : _name(origine._name) , _signed(origine._signed), _s_grade(origine._s_grade), _e_grade(origine._e_grade) {
	std::cout << "Copy constructor operator called" << std::endl;
}

AForm &AForm::operator=(const AForm &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origine)
		this->_signed = origine._signed;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const AForm &c) {
	if (c.getSigned())
		out << "Name of form is " << c.getName() << "." << std::endl << "The Form is signed." << std::endl << "The grade required to execute is " << c.getEGrade() << "." << std::endl << "And the grade required to sign is " << c.getSGrade() << ".";
	else
		out << "Name of form is " << c.getName() << "." << std::endl << "The Form is not signed." << std::endl << "The grade required to execute is " << c.getEGrade() << "." << std::endl << "And the grade required to sign is " << c.getSGrade() << ".";
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

void AForm::beSigned(const Bureaucrat &origine) {
	if (origine.getGrade() > this->_s_grade)
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

