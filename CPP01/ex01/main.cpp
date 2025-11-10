/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:44:22 by rjaada            #+#    #+#             */
/*   Updated: 2025/10/08 14:38:57 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 26;
	Zombie *zombies = zombieHorde(N, "HordeZombie");
	int i = 0;
	while (i < N)
	{
		std::cout << "[" << i + 1 << "] ";
		zombies[i].announce();
		i++;
	}
	delete[] zombies;
	return 0;
}