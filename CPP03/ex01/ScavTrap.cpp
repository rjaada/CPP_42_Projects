/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:16:15 by rjaada            #+#    #+#             */
/*   Updated: 2025/12/10 20:33:22 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() /*: hit_points(10), energy_points(10), attack_damage(0) */
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string nm) : ClapTrap(nm) /*: name(nm), hit_points(10), energy_points(10), attack_damage(0) */
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) /* : name(copy.name), hit_points(copy.hit_points), energy_points(copy.energy_points), attack_damage(copy.attack_damage) */
{
	/* this->name = copy.name;
	this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage; */
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if(this != &copy)
		ClapTrap::operator=(copy);
	/* {
		this->attack_damage = copy.attack_damage;
		this->energy_points = copy.energy_points;
		this->hit_points = copy.hit_points;
		this->name = copy.name;
	} */
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hit_points <= 0)
        std::cout << this->name << " can't attack because there's no hit points" << std::endl;
    else if (this->energy_points <= 0)
        std::cout << this->name << " can't attack because there's no energy points" << std::endl;
    else
    {
        --this->energy_points;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
}

/* void ScavTrap::takeDamage(unsigned int amount)
{
	this->hit_points -= static_cast<int>(amount);
	if (this->hit_points < 0)
        this->hit_points = 0;
	 std::cout << "ScavTrap " << this->name << " takes " << amount << " points of damage and has " << this->hit_points << " hit points left" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points <= 0)
        std::cout << this->name << " can't be repaired because there's no hit points" << std::endl;
    else if (this->energy_points <= 0)
		std::cout << this->name << " can't be repaired because there's no energy points" << std::endl;
	else
	{
		this->energy_points -= 1;
		this->hit_points += static_cast<int>(amount);
		std::cout << "ScavTrap " << this->name << " repairs itself for " << amount << " points and now has " << this->hit_points << " hit points and " << this->energy_points << " energy points" << std::endl;
	}
} */

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap "<< this->name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor is called for " << this->name << std::endl;
}