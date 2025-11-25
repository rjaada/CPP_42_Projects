/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:16:51 by rjaada            #+#    #+#             */
/*   Updated: 2025/11/10 20:05:07 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*int main(void)
{
	ClapTrap ClapTrap("rachid");
	ClapTrap.attack("target");
	ClapTrap.takeDamage(1);
	ClapTrap.beRepaired(1);
	std::cout << "THE ATTACKS ITS FINALLY DONE" << std::endl;
	return 0;
}*/

int main(void)
{
    std::cout << "=== CLAPTRAP TEST START ===" << std::endl;

    ClapTrap r("rachid");
    r.attack("target");
    r.takeDamage(1);
    r.beRepaired(1);

    std::cout << "\n--- Copy constructor ---" << std::endl;
    ClapTrap c(r); // copy ctor
    c.attack("dummy");
    c.takeDamage(2);

    std::cout << "\n--- Assignment ---" << std::endl;
    ClapTrap a;
    a = r; // copy assignment
    a.beRepaired(3);

    std::cout << "\n--- Deplete energy (calls to beRepaired) ---" << std::endl;
    for (int i = 0; i < 12; ++i)
    {
        std::cout << "repair #" << i + 1 << ": ";
        a.beRepaired(1);
    }

    std::cout << "\n=== CLAPTRAP TEST END ===" << std::endl;
    return 0;
}