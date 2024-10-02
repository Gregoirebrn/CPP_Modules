/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:29:44 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/02 14:34:20 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	std::cout << "Bureaucrat second constructor called" << std::endl;
	check_grade(grade);
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &origine) : _name(origine._name){
	std::cout << "Copy constructor operator called" << std::endl;
	this->_grade = origine._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origine)
		this->_grade = origine._grade;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &c)
{
	out << c.getName() << ", bureaucrat grade " << c.getGrade() << ".";
	return out;
}

std::string const Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::check_grade(int grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

void Bureaucrat::incr_grade()
{
	this->_grade--;
	check_grade(_grade);
}

void Bureaucrat::decr_grade()
{
	this->_grade++;
	check_grade(_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is Too High.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is Too Low.");
}
