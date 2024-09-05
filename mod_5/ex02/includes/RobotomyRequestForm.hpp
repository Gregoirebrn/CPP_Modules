/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:40:57 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/05 18:40:57 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;
public:
	RobotomyRequestForm(const std::string &name);
	~RobotomyRequestForm();
	RobotomyRequestForm (const RobotomyRequestForm &origine);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &origine);

	void	execute(const RobotomyRequestForm &base) const ;
};

#endif