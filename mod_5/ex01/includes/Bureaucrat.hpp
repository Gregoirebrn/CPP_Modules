/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:29:33 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 12:59:47 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Bureaucrat{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat() : _name("default"), _grade(1) {}
	~Bureaucrat();
	Bureaucrat (const Bureaucrat &origin);
	Bureaucrat &operator=(const Bureaucrat &origin);

	std::string const getName() const ;
	int		getGrade() const ;

	void	incr_grade();
	void	decr_grade();
	void	check_grade(int grade);

	void	signForm(Form &Form);
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c);

#endif
