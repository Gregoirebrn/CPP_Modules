/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                         :+:      :+:    :+:   */
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

class ScalarConverter{
private:
	const std::string	_name;
	int					_grade;
public:
	ScalarConverter(const std::string &name, int grade);
	~ScalarConverter();
	ScalarConverter (const ScalarConverter &origine);
	ScalarConverter &operator=(const ScalarConverter &origine);

	std::string getName() const ;
	int		getGrade() const ;

	void	incr_grade(int add);
	void	decr_grade(int minus);
	static void	check_grade(int grade);

	void executeForm(AForm const & form) const;

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

std::ostream &operator << (std::ostream &out, const ScalarConverter &c);

#endif
