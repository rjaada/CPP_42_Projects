/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-15 15:14:42 by rjaada            #+#    #+#             */
/*   Updated: 2026-05-15 15:14:42 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP


# include <iostream>
# include <string>
# include <algorithm>
# include <exception>


template <typename T>
typename T::iterator easyfind(T container, int i)
{
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw std::exception();
	else
		return it;
}





#endif