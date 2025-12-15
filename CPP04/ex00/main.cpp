/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 16:36:10 by rjaada            #+#    #+#             */
/*   Updated: 2025-12-15 16:36:10 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "cat.hpp"
#include "dog.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->GetType() << " " << std::endl;
	std::cout << i->GetType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n=== SIMPLE ANIMAL TEST ===" << std::endl;

	// 1. Default Constructor
	std::cout << "\n--- 1. Default Constructor ---" << std::endl;
	Animal meta;
	std::cout << "Type: " << meta.GetType() << std::endl;
	std::cout << "Sound: ";
	meta.makeSound();

	// 2. Copy Constructor
	std::cout << "\n--- 2. Copy Constructor ---" << std::endl;
	Animal copy(meta);
	std::cout << "Copy Type: " << copy.GetType() << std::endl;
	std::cout << "Copy Sound: ";
	copy.makeSound();

	// 3. Assignment Operator
	std::cout << "\n--- 3. Assignment Operator ---" << std::endl;
	Animal assigned;
	assigned = meta;
	std::cout << "Assigned Type: " << assigned.GetType() << std::endl;
	std::cout << "Assigned Sound: ";
	assigned.makeSound();

	std::cout << "\n=== SIMPLE CAT TEST ===" << std::endl;

	// 1. Default Constructor
	std::cout << "\n--- 1. Default Constructor ---" << std::endl;
	Cat Eren;
	std::cout << "Type: " << Eren.GetType() << std::endl;
	std::cout << "Sound: ";
	Eren.makeSound();

	// 2. Copy Constructor
	std::cout << "\n--- 2. Copy Constructor ---" << std::endl;
	Animal copy_cat(Eren);
	std::cout << "Copy Type: " << Eren.GetType() << std::endl;
	std::cout << "Copy Sound: ";
	copy_cat.makeSound();

	// 3. Assignment Operator
	std::cout << "\n--- 3. Assignment Operator ---" << std::endl;
	Animal assigned_cat;
	assigned_cat = Eren;
	std::cout << "Assigned Type: " << assigned_cat.GetType() << std::endl;
	std::cout << "Assigned Sound: ";
	assigned_cat.makeSound();

	std::cout << "\n=== SIMPLE DOG TEST ===" << std::endl;

	// 1. Default Constructor
	std::cout << "\n--- 1. Default Constructor ---" << std::endl;
	Dog Dawg;
	std::cout << "Type: " << Dawg.GetType() << std::endl;
	std::cout << "Sound: ";
	Dawg.makeSound();

	// 2. Copy Constructor
	std::cout << "\n--- 2. Copy Constructor ---" << std::endl;
	Animal copy_dog(Dawg);
	std::cout << "Copy Type: " << Dawg.GetType() << std::endl;
	std::cout << "Copy Sound: ";
	copy_dog.makeSound();

	// 3. Assignment Operator
	std::cout << "\n--- 3. Assignment Operator ---" << std::endl;
	Animal assigned_dog;
	assigned_dog = Dawg;
	std::cout << "Assigned Type: " << assigned_dog.GetType() << std::endl;
	std::cout << "Assigned Sound: ";
	assigned_dog.makeSound();

	std::cout << "\n=== END TEST ===" << std::endl;

	return (0);
}