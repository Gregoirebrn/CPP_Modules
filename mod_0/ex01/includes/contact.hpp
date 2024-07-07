/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:56:18 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/07 12:56:18 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact {
public:
	Contact(void);
	bool get_infos(void);
private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
};

#endif