/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:46:16 by rjaada            #+#    #+#             */
/*   Updated: 2025/10/08 14:25:16 by rjaada           ###   ########.fr       */
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
		Zombie();
		~Zombie();
		void setName(std::string name);
	private:
	std::string name;
};

Zombie* zombieHorde(int N, std::string name);
#endif