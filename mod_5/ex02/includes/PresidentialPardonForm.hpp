/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:27:09 by grebrune          #+#    #+#             */
/*   Updated: 2024/10/03 13:47:15 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string const &name);
	~PresidentialPardonForm() {}
	PresidentialPardonForm (const PresidentialPardonForm &origin);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &origin);

	int	execute(Bureaucrat const & executor) const ;
};

#endif