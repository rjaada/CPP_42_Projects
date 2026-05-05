/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-05 02:55:55 by rjaada            #+#    #+#             */
/*   Updated: 2026-05-05 02:55:55 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T, typename F> void iter(T* arr, int const lenght, F func)
{
	for (int i = 0; i < lenght; i++)
		func(arr[i]);
}


#endif