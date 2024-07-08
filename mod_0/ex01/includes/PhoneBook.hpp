/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:26:35 by grebrune          #+#    #+#             */
/*   Updated: 2024/07/08 11:57:44 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook {
	public :
		void	Creator(void);
		void	new_contact(void);
		void	search(void);
	private :
		Contact	friends[8];
		int		index;
		int		nbr_friends;
};


#endif