/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:05:09 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/04 19:03:51 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int eg, int sg) : _name(name), _s_grade(sg), _e_grade(eg)
{
	std::cout << "Form second constructor called" << std::endl;
	this->_signed = false; }

Form::~Form() {
	std::cout << "Form default destructor called" << std::endl; }

Form::Form(const Form &origine) : _name(origine._name) , _s_grade(origine._s_grade), _e_grade(origine._e_grade) {
	std::cout << "Copy constructor operator called" << std::endl;
	_signed = origine._signed; }

Form &Form::operator=(const Form &origine) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origine)
		this->_signed = origine._signed;
	return (*this); }

std::ostream & operator << (std::ostream &out, const Form &c)
{
	out << c.getName() << ", is signed " << c.getSigned() << " required to execute it " << c.getEGrade() << " grade required to sign it " << c.getSGrade() << ".";
	return out; }

std::string Form::getName() const
{
	return this->_name; }

int Form::getEGrade() const
{
	return (this->_e_grade); }

int Form::getSGrade() const
{
	return (this->_s_grade); }

int Form::getSigned() const
{
	return (this->_signed); }

void Form::beSigned(const Bureaucrat &origine)
{
	if (origine.getGrade() >= this->_s_grade)
		throw (Form::GradeTooLowException());
	this->_signed = true; }

const char *Form::GradeTooHighException::what() const throw()
{
	return ("The grade is Too High."); }

const char *Form::GradeTooLowException::what() const throw()
{
	return ("The grade is Too Low."); }

