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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "cat.hpp"
#include "dog.hpp"

int	main(void)
{
    std::cout << "=== Animal Class ===" << std::endl;
    Animal* my_animal = new Animal();
    my_animal->makeSound();
    delete my_animal;
    
    std::cout << std::endl << "=== Cat Class ===" << std::endl;
    Cat* my_cat = new Cat();
    my_cat->makeSound();
    delete my_cat;
    
    Animal* my_an_cat = new Cat();
    my_an_cat->makeSound();
    delete my_an_cat;

    std::cout << std::endl << "=== Dog Class ===" << std::endl;
    Dog* my_dog = new Dog();
    my_dog->makeSound();
    delete my_dog;

    Animal* my_an_dog = new Dog();
    my_an_dog->makeSound();
    delete my_an_dog;

    std::cout << std::endl << "=== Right Classes ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << " Type: " << j->getType() << " " << std::endl;
    std::cout << " Type: " << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << std::endl << "=== Wrong Classes ===" << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* y = new WrongCat();
    std::cout << " Type: " << y->getType() << " " << std::endl;
    y->makeSound(); //will output the WrongAnimal sound!
    wrong_meta->makeSound();
    delete wrong_meta;
    delete y;
    
	return 0;
	
	
	
	
	
	
	
	
	
	/* std::cout << "\n=== SIMPLE ANIMAL TEST ===" << std::endl;

	// 1. Default Constructor
	std::cout << "\n--- 1. Default Constructor ---" << std::endl;
	Animal meta2;
	std::cout << "Type: " << meta->getType() << std::endl;
	std::cout << "Sound: ";
	meta->makeSound();

	// 2. Copy Constructor
	std::cout << "\n--- 2. Copy Constructor ---" << std::endl;
	Animal copy(*meta);
	std::cout << "Copy Type: " << copy.getType() << std::endl;
	std::cout << "Copy Sound: ";
	copy.makeSound();

	// 3. Assignment Operator
	std::cout << "\n--- 3. Assignment Operator ---" << std::endl;
	Animal assigned;
	assigned = *meta;
	std::cout << "Assigned Type: " << assigned.getType() << std::endl;
	std::cout << "Assigned Sound: ";
	assigned.makeSound();

	std::cout << "\n=== SIMPLE CAT TEST ===" << std::endl;

	// 1. Default Constructor
	std::cout << "\n--- 1. Default Constructor ---" << std::endl;
	Cat Eren;
	std::cout << "Type: " << Eren.getType() << std::endl;
	std::cout << "Sound: ";
	Eren.makeSound();

	// 2. Copy Constructor
	std::cout << "\n--- 2. Copy Constructor ---" << std::endl;
	Animal copy_cat(Eren);
	std::cout << "Copy Type: " << Eren.getType() << std::endl;
	std::cout << "Copy Sound: ";
	copy_cat.makeSound();

	// 3. Assignment Operator
	std::cout << "\n--- 3. Assignment Operator ---" << std::endl;
	Animal assigned_cat;
	assigned_cat = Eren;
	std::cout << "Assigned Type: " << assigned_cat.getType() << std::endl;
	std::cout << "Assigned Sound: ";
	assigned_cat.makeSound();

	std::cout << "\n=== SIMPLE DOG TEST ===" << std::endl;

	// 1. Default Constructor
	std::cout << "\n--- 1. Default Constructor ---" << std::endl;
	Dog Dawg;
	std::cout << "Type: " << Dawg.getType() << std::endl;
	std::cout << "Sound: ";
	Dawg.makeSound();

	// 2. Copy Constructor
	std::cout << "\n--- 2. Copy Constructor ---" << std::endl;
	Animal copy_dog(Dawg);
	std::cout << "Copy Type: " << Dawg.getType() << std::endl;
	std::cout << "Copy Sound: ";
	copy_dog.makeSound();

	// 3. Assignment Operator
	std::cout << "\n--- 3. Assignment Operator ---" << std::endl;
	Animal assigned_dog;
	assigned_dog = Dawg;
	std::cout << "Assigned Type: " << assigned_dog.getType() << std::endl;
	std::cout << "Assigned Sound: ";
	assigned_dog.makeSound();

	std::cout << "\n=== END TEST ===" << std::endl; */

}