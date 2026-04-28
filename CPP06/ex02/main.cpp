/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-28 06:45:50 by rjaada            #+#    #+#             */
/*   Updated: 2026-04-28 06:45:50 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;
	return (0);
}
