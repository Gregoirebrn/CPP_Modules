/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:41:02 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 14:10:12 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cmath>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45) , _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &origin) : AForm(origin), _target(origin._target) {
	std::cout << "Copy constructor operator called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origin)
	{
		this->AForm::operator=(origin);
		_target = origin._target;
	}
	return (*this);
}

int RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	is_grade_exe(executor);
	srand(time(NULL));
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
	return (0);
}
