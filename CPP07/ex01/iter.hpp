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

template <typename T> void iter(T* arr, int const lenght, void (*func)(T &))
{
	for (int i = 0; i < lenght; i++)
		func(arr[i]);
}


#endif