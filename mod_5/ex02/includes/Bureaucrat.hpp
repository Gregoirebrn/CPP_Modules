/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:48:16 by grebrune          #+#    #+#             */
/*   Updated: 2024/08/01 13:27:30 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat (const Bureaucrat &origine);
	Bureaucrat &operator=(const Bureaucrat &origine);

	std::string getName() const ;
	int		getGrade() const ;

	void	incr_grade(int add);
	void	decr_grade(int minus);
	static void	check_grade(int grade);

	void	signForm(const AForm &Form) const ;
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &c);

#endif
