/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-08 15:30:25 by rjaada            #+#    #+#             */
/*   Updated: 2026-05-08 15:30:25 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRYA_HPP

# include <iostream>
# include <string>

template <typename T> class Array
{
private:
	int size;
	T *myarray;
public:
	Array();
	Array(unsigned int n);
	Array(Array const &other);
	Array &operator=(const Array &copy);
	~Array();
	int size();
};





#endif