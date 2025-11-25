/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:16:48 by rjaada            #+#    #+#             */
/*   Updated: 2025/11/10 20:23:35 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string nm) : name(nm), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : name(copy.name), hit_points(copy.hit_points), energy_points(copy.energy_points), attack_damage(copy.attack_damage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if(this != &copy)
	{
		this->attack_damage = copy.attack_damage;
		this->energy_points = copy.energy_points;
		this->hit_points = copy.hit_points;
		this->name = copy.name;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hit_points <= 0)
        std::cout << this->name << " can't attack because there's no hit points" << std::endl;
    else if (this->energy_points <= 0)
        std::cout << this->name << " can't attack because there's no energy points" << std::endl;
    else
    {
        --this->energy_points;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hit_points -= static_cast<int>(amount);
	if (this->hit_points < 0)
        this->hit_points = 0;
	 std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage and has " << this->hit_points << " hit points left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points <= 0)
        std::cout << this->name << " can't be repaired because there's no hit points" << std::endl;
    else if (this->energy_points <= 0)
		std::cout << this->name << " can't be repaired because there's no energy points" << std::endl;
	else
	{
		this->energy_points -= 1;
		this->hit_points += static_cast<int>(amount);
		std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " points and now has " << this->hit_points << " hit points and " << this->energy_points << " energy points" << std::endl;
	}
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor is called for " << this->name << std::endl;
}