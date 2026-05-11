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
# define ARRAY_HPP

# include <cstdlib>
# include <ctime>
# include <exception>
# include <iostream>
# include <string>

template <typename T> class Array
{
  private:
	unsigned int s;
	T *myarray;

  public:
	Array() : s(0), myarray(NULL)
	{
	}
	Array(unsigned int n) : s(n), myarray(new T[n])
	{
	}
	Array(Array const &other) : s(other.s), myarray(new T[s])
	{
		for (unsigned int i = 0; i < s; i++)
			myarray[i] = other.myarray[i];
	}
	Array &operator=(const Array &copy)
	{
		if (this != &copy)
		{
			delete[] myarray;
			s = copy.s;
			myarray = new T[s];
			for (unsigned int i = 0; i < s; i++)
				myarray[i] = copy.myarray[i];
		}
		return (*this);
	}
	~Array()
	{
		delete[] myarray;
	}
	unsigned int size() const
	{
		return (s);
	}
	T &operator[](unsigned int index)
	{
		if (index >= s)
			throw std::exception();
		return (myarray[index]);
	}
	const T &operator[](unsigned int index) const
	{
		if (index >= s)
			throw std::exception();
		return (myarray[index]);
	}
};

#endif