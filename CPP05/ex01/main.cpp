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
#include "Form.hpp"

int main(void)
{
    std::cout << "--- CREATION TESTS ---" << std::endl;
    try {
        Form impossible("Impossible", 0, 50); // Should throw
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Form easy("Easy", 150, 150);
        Form hard("Hard", 1, 1);
        Bureaucrat chad("Chad", 1);
        Bureaucrat noob("Noob", 150);

        std::cout << "\n--- FORM INFO ---" << std::endl;
        std::cout << easy;
        std::cout << hard;

        std::cout << "\n--- SIGNING TESTS ---" << std::endl;
        
        // Noob tries to sign hard form (Fails)
        noob.signForm(hard);
        
        // Noob tries to sign easy form (Success)
        noob.signForm(easy);

        // Chad signs hard form (Success)
        chad.signForm(hard);

        std::cout << "\n--- FINAL FORM INFO ---" << std::endl;
        std::cout << easy;
        std::cout << hard;

    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
