/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:29:48 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/31 15:30:17 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

ScalarConverter::ScalarConverter(const std::string &name, int grade) : _name(name)
{
	std::cout << "ScalarConverter second constructor called" << std::endl;
	check_grade(grade);
	this->_grade = grade;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter default destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &origine) : _name(origine._name){
	std::cout << "Copy constructor operator called" << std::endl;
	this->_grade = origine._grade;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origine)
		this->_grade = origine._grade;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const ScalarConverter &c)
{
	out << c.getName() << ", bureaucrat grade " << c.getGrade() << ".";
	return out;
}

std::string ScalarConverter::getName() const
{
	return this->_name;
}

int ScalarConverter::getGrade() const
{
	return (this->_grade);
}

void	ScalarConverter::check_grade(int grade)
{
	if (grade < 1)
		throw (ScalarConverter::GradeTooHighException());
	if (grade > 150)
		throw (ScalarConverter::GradeTooLowException());
}

void ScalarConverter::incr_grade(int add)
{
	this->_grade += add;
	check_grade(_grade);
}

void ScalarConverter::decr_grade(int minus)
{
	this->_grade -= minus;
	check_grade(_grade);
}

const char *ScalarConverter::GradeTooHighException::what() const throw()
{
	return ("The grade is Too High.");
}

const char *ScalarConverter::GradeTooLowException::what() const throw()
{
	return ("The grade is Too Low.");
}

void ScalarConverter::signForm(const AForm &Form) const
{
	if (Form.getSigned())
		std::cout << _name << " signed " << Form.getName() << "." << std::endl;
	else {
		std::cout << _name << " couldn't sign " << Form.getName() << " because ";
		throw (AForm::GradeTooLowException());
	}
}

void ScalarConverter::executeForm(const AForm &form) const {
	if (!form.execute(*this))
		std::cout << this->getName() << " executed " << form.getName();
}
