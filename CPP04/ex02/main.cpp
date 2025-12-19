/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:36:10 by rjaada            #+#    #+#             */
/*   Updated: 2025/12/19 01:30:53 by rjaada           ###   ########.fr       */
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
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Dog Type: " << dog->getType() << std::endl;
    dog->makeSound(); // output: "woof woof woof"
    
    std::cout << "Cat Type: " << cat->getType() << std::endl;
    cat->makeSound(); // output: "Meowwwwwwwwwww"

    /* Animal test; 
    Animal* test2 = new Animal();
 */
    delete dog;
    delete cat;

    return 0;
}