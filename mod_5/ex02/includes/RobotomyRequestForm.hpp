/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:40:57 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/06 19:00:09 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string const &name);
	~RobotomyRequestForm();
	RobotomyRequestForm (const RobotomyRequestForm &origin);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &origin);

	int	execute(Bureaucrat const & executor) const ;
};

#endif