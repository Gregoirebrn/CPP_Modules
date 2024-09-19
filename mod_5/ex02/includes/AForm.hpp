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

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class ScalarConverter;

class AForm{
private:
	const std::string	_name;
	bool				_signed;
	const int					_s_grade;
	const int					_e_grade;
public:
	AForm(const std::string &name, int eg, int sg);
	AForm();
	virtual ~AForm();
	AForm (const AForm &origine);
	AForm &operator=(const AForm &origine);

	std::string getName() const ;
	int		getSigned() const ;
	int		getEGrade() const ;
	int		getSGrade() const ;
	void	beSigned(const ScalarConverter &origine) ;

	void	is_grade_exe(ScalarConverter const & executor) const ;
	virtual int	execute(ScalarConverter const & executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class IsNotSigned : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
