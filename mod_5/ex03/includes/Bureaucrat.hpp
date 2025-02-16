/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:43:10 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 13:47:15 by grebrune         ###   ########.fr       */
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
	Bureaucrat() : _name("default"), _grade(1) {}
	~Bureaucrat() {}
	Bureaucrat (const Bureaucrat &origin);
	Bureaucrat &operator=(const Bureaucrat &origin);

	std::string getName() const ;
	int		getGrade() const ;

	void	incr_grade();
	void	decr_grade();
	static void	check_grade(int grade);

	void executeForm(AForm const & form) const;

	void	signForm(const AForm &Form) const ;
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
