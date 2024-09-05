/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:06:40 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/05 14:25:46 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm{
private:
	const std::string	_name;
	bool				_signed;
	const int					_s_grade;
	const int					_e_grade;
public:
	AForm(const std::string &name, int eg, int sg);
	~AForm();
	AForm (const AForm &origine);
	AForm &operator=(const AForm &origine);

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

#endif
