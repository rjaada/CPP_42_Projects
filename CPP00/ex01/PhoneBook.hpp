/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:13:21 by rjaada            #+#    #+#             */
/*   Updated: 2025/06/12 23:31:56 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>
# include <iostream>
# include <string>

class PhoneBook
{
  public:
	PhoneBook();
	void search();
	void add();
	void exit();

  private:
	int contact_counter;
	Contact contact[8];
};

#endif