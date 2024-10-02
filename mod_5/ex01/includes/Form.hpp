/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:30:38 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/02 11:30:38 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form{
private:
	const std::string	_name;
	bool				_signed;
	const int			_s_grade;
	const int			_e_grade;
public:
	Form(const std::string &name, int eg, int sg);
	~Form();
	Form (const Form &origine);
	Form &operator=(const Form &origine);

	std::string getName() const ;
	int		getSigned() const ;
	int		getEGrade() const ;
	int		getSGrade() const ;

	void	beSigned(const Bureaucrat &origine) ;
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream &operator << (std::ostream &out, const Form &c);

#endif
