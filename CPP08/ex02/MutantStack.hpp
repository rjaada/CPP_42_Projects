/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-24 20:45:54 by rjaada            #+#    #+#             */
/*   Updated: 2026-06-24 20:45:54 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <string>
# include <vector>

template <typename T> class MutantStack : public std::stack<T>
{
  public:
	MutantStack() : std::stack<T>(){}
	MutantStack(MutantStack const &other) : std::stack<T>(other){}
	MutantStack &operator=(MutantStack const &other)
	{
		if (this != &other)
			std::stack<T>::operator=(other);
		return (*this);
	}
	~MutantStack(){}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}
};

#endif