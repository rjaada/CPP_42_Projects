/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:10:03 by rjaada            #+#    #+#             */
/*   Updated: 2025/06/13 01:03:26 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contact_counter = 0;
}

void PhoneBook::add()
{
	contact[contact_counter].set_info();
	std::cout << "\ncontact number " << contact_counter
		+ 1 << " is added to the PhoneBook\n";
	contact_counter++;
	if (contact_counter == 8)
		contact_counter = 0;
}

void PhoneBook::search()
{
	int i;
	int choice;
	bool has_contacts;

	has_contacts = false;
	i = 0;
	while (i < 8)
	{
		if (!contact[i].is_empty())
			has_contacts = true;
		i++;
	}

	if (!has_contacts)
	{
		std::cout << "No contacts available.\n";
		return;
	}

	std::cout << "     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "----------|----------|----------|----------|\n";
	i = 0;
	while (i < 8)
	{
		if (!contact[i].is_empty())
			contact[i].display_table(i + 1);
		i++;
	}

	std::cout << "Enter index of contact to display: ";
	std::cin >> choice;
	std::cin.ignore();

	if (choice < 1 || choice > 8 || contact[choice - 1].is_empty())
	{
		std::cout << "Invalid index.\n";
		return;
	}

	contact[choice - 1].show_info();
}
void PhoneBook::exit()
{
	std::cout << "Goodbye! Thanks for using PhoneBook!\n";
	std::exit(0);
}