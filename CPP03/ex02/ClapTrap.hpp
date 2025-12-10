/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:16:53 by rjaada            #+#    #+#             */
/*   Updated: 2025/12/10 19:36:46 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string nm);
		ClapTrap(const ClapTrap &copy);
		ClapTrap& operator=(const ClapTrap &copy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		/*void set_name(std::string nm)
		{
			this->name = nm;
		}*/
		~ClapTrap();
};



#endif