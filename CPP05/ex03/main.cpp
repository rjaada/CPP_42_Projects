/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:26:14 by rjaada            #+#    #+#             */
/*   Updated: 2026/04/13 21:34:29 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    
    std::cout << "\n--- INTERN WORKING ---" << std::endl;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Zaphod");
    AForm* fail = someRandomIntern.makeForm("invalid form", "Nobody");

    std::cout << "\n--- BOSS TESTS THE ROBOTOMY ---" << std::endl;
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
    }

    std::cout << "\n--- CLEANUP ---" << std::endl;
    delete rrf;
    delete scf;
    delete ppf;
    delete fail; // C++ handles delete NULL fine

    return 0;
}