/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-05 01:08:25 by rjaada            #+#    #+#             */
/*   Updated: 2026-05-05 01:08:25 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{

	int a = 2;
	int b = 3;
	
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	return (0);





    /* int x = 5;
    int y = 5;
    std::cout << "min(5, 5) = " << ::min(x, y) << std::endl;
    std::cout << "max(5, 5) = " << ::max(x, y) << std::endl;

    float f1 = 1.5f;
    float f2 = 2.5f;
    ::swap(f1, f2);
    std::cout << "after swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;

    char c1 = 'a';
    char c2 = 'z';
    std::cout << "min('a', 'z') = " << ::min(c1, c2) << std::endl;
    std::cout << "max('a', 'z') = " << ::max(c1, c2) << std::endl;

    int n1 = -10;
    int n2 = -3;
    std::cout << "min(-10, -3) = " << ::min(n1, n2) << std::endl;
    std::cout << "max(-10, -3) = " << ::max(n1, n2) << std::endl;

    return (0); */
}
