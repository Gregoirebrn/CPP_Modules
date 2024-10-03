/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:28:25 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 17:01:56 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
	check_grade(grade);
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &origin) : _name(origin._name){
	std::cout << "Copy constructor operator called" << std::endl;
	this->_grade = origin._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origin)
		this->_grade = origin._grade;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &c) {
	out << c.getName() << ", bureaucrat grade is " << c.getGrade() << ".";
	return out;
}

std::string const Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::check_grade(int grade) {
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

void Bureaucrat::incr_grade() {
	check_grade(_grade - 1);
	this->_grade--;
}

void Bureaucrat::decr_grade() {
	check_grade(_grade + 1);
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("The grade is Too High.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The grade is Too Low.");
}

void Bureaucrat::signForm(AForm &Form) {
	try {
		Form.beSigned(*this);
		std::cout << _name << " signed " << Form.getName() << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << Form.getName() << " because the grade is too low!" << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const {
	if (!form.execute(*this))
		std::cout << this->getName() << " executed " << form.getName();
}
