/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:16:51 by rjaada            #+#    #+#             */
/*   Updated: 2025/12/10 20:50:28 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	std::cout << "\n=== SCAVTRAP TEST START ===" << std::endl;

    ScavTrap s("scav");
    s.attack("enemy");
    s.takeDamage(10);
    s.beRepaired(5);
    s.guardGate();

    std::cout << "\n--- ScavTrap Copy Constructor ---" << std::endl;
    ScavTrap s2(s);
    s2.attack("another");

    std::cout << "\n--- ScavTrap Assignment ---" << std::endl;
    ScavTrap s3;
    s3 = s;
    s3.guardGate();

    std::cout << "\n=== SCAVTRAP TEST END ===" << std::endl;

	// --- PART 3: FRAGTRAP TEST (Ex02) ---
    std::cout << "\n=== 3. FRAGTRAP TEST (Ex02) ===" << std::endl;
    
    // 3a. Default Constructor & Stat Check
    FragTrap f1("frag_alpha");
    std::cout << "\n--- FRAGTRAP STAT CHECK ---" << std::endl;
    
    // Check Damage: Must be 30
    f1.attack("boss"); 
    
    // Check HP and Energy drain
    f1.takeDamage(10); // HP: 100 -> 90
    f1.beRepaired(10); // HP: 90 -> 100, Energy: 100 -> 99
    
    // Check Special Ability
    f1.highFivesGuys();

    // 3b. OCF/Chaining Check
    std::cout << "\n--- FRAGTRAP OCF CHECK ---" << std::endl;
    
    // Copy Constructor
    FragTrap f2(f1);
    
    // Copy Assignment
    FragTrap f3;
    f3 = f2;
    f3.attack("copy_target"); // Should attack for 30

    // 3c. Energy Depletion Test (Needs 100 Energy points to confirm)
    std::cout << "\n--- FRAGTRAP ENERGY DEPLETION ---" << std::endl;
    for (int i = 0; i < 101; ++i)
    {
        std::cout << "Attack #" << i + 1 << ": ";
        f3.attack("dummy_target");
    }


    std::cout << "\n=== ALL TESTS END ===\n" << std::endl;
    return 0;
}