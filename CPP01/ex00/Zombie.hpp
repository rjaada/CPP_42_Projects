/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:46:16 by rjaada            #+#    #+#             */
/*   Updated: 2025/10/08 13:06:35 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		void announce() const;
		Zombie(std::string name);
		~Zombie();
		
	private:
	std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
#endif