/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:43:07 by rjaada            #+#    #+#             */
/*   Updated: 2025/12/10 20:45:21 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	/* private:
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage; */
	public:
		FragTrap();
		FragTrap(std::string nm);
		FragTrap(const FragTrap &copy);
		FragTrap& operator=(const FragTrap &copy);
		void attack(const std::string& target);
		/* void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount); */
		/*void set_name(std::string nm)
		{
			this->name = nm;
			}*/
		void guardGate();
		void highFivesGuys(void);
		~FragTrap();
};

#endif