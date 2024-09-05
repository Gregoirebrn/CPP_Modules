/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:27:09 by grebrune          #+#    #+#             */
/*   Updated: 2024/09/05 17:30:08 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;
public:
	PresidentialPardonForm(std::string &name);
	~PresidentialPardonForm();
	PresidentialPardonForm (const PresidentialPardonForm &origine);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &origine);

	void	execute(const PresidentialPardonForm &base) const ;
};

#endif