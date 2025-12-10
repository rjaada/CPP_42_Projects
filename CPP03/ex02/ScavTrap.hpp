/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:16:17 by rjaada            #+#    #+#             */
/*   Updated: 2025/12/10 20:14:09 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	/* private:
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage; */
	public:
		ScavTrap();
		ScavTrap(std::string nm);
		ScavTrap(const ScavTrap &copy);
		ScavTrap& operator=(const ScavTrap &copy);
		void attack(const std::string& target);
		/* void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount); */
		/*void set_name(std::string nm)
		{
			this->name = nm;
			}*/
		void guardGate();
		~ScavTrap();
};

#endif