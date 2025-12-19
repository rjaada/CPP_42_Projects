/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:36:10 by rjaada            #+#    #+#             */
/*   Updated: 2025/12/19 01:16:38 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "cat.hpp"
#include "dog.hpp"

#define N_ANIMALS 10

int	main(void)
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j; // should not create a leak
	delete i;
	std::cout << "\n" << std::endl;

	std::cout << "========= 1. MANDATORY ARRAY TEST =========" << std::endl;
    // Subject Requirement: Create and fill an array of Animal objects
    const Animal* animals[N_ANIMALS];

    for (int i = 0; i < N_ANIMALS; i++)
    {
        if (i < N_ANIMALS / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // Subject Requirement: Loop over this array and delete every Animal
    std::cout << "\n[Deleting Array...]" << std::endl;
    for (int i = 0; i < N_ANIMALS; i++)
    {
        delete animals[i];
    }

    std::cout << "\n========= 2. COPY CONSTRUCTOR TEST (Deep Copy) =========" << std::endl;
    Dog dogA;
    dogA.setIdea(0, "Bone");

    Dog dogB(dogA); // Calls Copy Constructor

    std::cout << "Dog A Idea: " << dogA.getIdea(0) << std::endl;
    std::cout << "Dog B Idea: " << dogB.getIdea(0) << std::endl;

    std::cout << "-> Modifying Dog A..." << std::endl;
    dogA.setIdea(0, "Meat");

    std::cout << "Dog A Idea: " << dogA.getIdea(0) << std::endl;
    std::cout << "Dog B Idea: " << dogB.getIdea(0) << " (Should remain 'Bone')" << std::endl;


    std::cout << "\n========= 3. COPY ASSIGNMENT OPERATOR TEST (Deep Copy) =========" << std::endl;
    Cat catX;
    catX.setIdea(0, "Fish");

    Cat catY;
    catY.setIdea(0, "Sleep"); // Initial idea

    std::cout << "Before Assign -> Cat Y Idea: " << catY.getIdea(0) << std::endl;
    
    catY = catX; // Calls Assignment Operator (operator=)

    std::cout << "After Assign  -> Cat Y Idea: " << catY.getIdea(0) << " (Should be 'Fish')" << std::endl;

    std::cout << "-> Modifying Cat X..." << std::endl;
    catX.setIdea(0, "Mouse");

    std::cout << "Cat X Idea: " << catX.getIdea(0) << std::endl;
    std::cout << "Cat Y Idea: " << catY.getIdea(0) << " (Should remain 'Fish')" << std::endl;

    std::cout << "\n========= END OF TESTS =========" << std::endl;
    return 0;
}